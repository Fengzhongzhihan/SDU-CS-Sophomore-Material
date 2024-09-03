/*
 * SuffixTree.cpp
 *
 *  Created on: 2017年4月25日
 *      Author: lenovo
 */
/*
 * 记录当前操作的三元组
 *    三元组，  active-node：当前操作的节点
 *          active-edge：保存未来需要插入的字符串的首字母
 *	        active-length：保存未来需要插入的字符串的长度。
 *          初始为 root,0,0
 *    规则1：
 *当向根节点下子节点插入后缀后遵循：
 *active_node 保持为 root；
 *active_edge 被设置为即将被插入的新后缀的首字符；
 *active_length 减 1；
 *    规则2：
 *如果我们分裂（Split）一条边并且插入（Insert）一个新的节点，
 *并且如果该新节点不是当前步骤中创建的第一个节点，
 *则将先前插入的节点与该新节点通过一个特殊的指针连接，
 *称为后缀连接（Suffix Link）。后缀连接通过一条虚线来表示。
 *    规则3：
 *当从 active_node 不为 root 的节点分裂边时，
 *我们沿着后缀连接（Suffix Link）的方向寻找节点，
 *则设置该节点为 active_node；如果不存在，则设置 active_node 为 root。
 *active_edge 和 active_length 保持不变。
 *
 */
#include "SuffixTree.h"
#include "string.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include "windows.h"
using namespace std;
SuffixTree::SuffixTree()
{
	//初始化

	root->init("");
	activenode->init(root,NULL,0);

}

SuffixTree::~SuffixTree() {
	// TODO Auto-generated destructor stub
}

void SuffixTree::create(string str){//对字符串str构造后缀树
	int index = 0;//
	treeword=str;
	while (index < str.length()) {// 循环建立后缀

		int currentIndex = index++;// 保存当前的位置
		char w =str[currentIndex];// 得到当前的后缀字符
		bool f=find(w);
		if (f) {// 查找是否存在保存有当前后缀字符的节点
			remainder++;// 存在，则将reminder+1，activenode->length+1，结束本次循环
			continue;//跳过本次循环，即找到一个相同，在find方法内利用活动点记录一次，暂不处理
		}else if(!f&&!activenode->index&&remainder != 0){
			//找不到且此时index=0，且需要插入后缀（remainder=0）（活动点转移的情况）
			SuffixNode* child=activenode->point->Child;
			SuffixNode* splitNode=activenode->point;
			SuffixNode *newNode=new SuffixNode();//即将插入的节点
			string s=str.substr(currentIndex,str.length()-currentIndex);//待分裂的字符
			newNode->init(s);
			newNode->iiflag=iflag++;//newNode为新建立的叶子节点，对应有字符串起始位置
			//遍历活动节点孩子的兄弟节点，插到最后
			while(child->Brother!=NULL){
				child=child->Brother;
			}
			child->Brother=newNode;
			//以上为一次分割过程。
			// 再非root节点上进行操作，分割完成之后需根据规则3对待
			if (NULL== activenode->point->suffixNode) {// 无后缀节点，则活动节点变为root
				activenode->point = root;
			} else {// 否则活动节点变为当前活动节点的后缀节点
				activenode->point = activenode->point->suffixNode;
			}
				activenode->index=NULL;
				activenode->length=0;
				Split(str, currentIndex, splitNode);//eg:需要插入abx,bx,x,则处理完abx，后需要继续处理bx，进行分裂操作
				continue;
		}

		// 不存在的话，如果reminder==0表示之前在该字符之前未剩余有其他待插入的后缀字符，所以直接插入该后缀字符即可
		if (remainder == 0) {
			// 直接在当前活动节点插入一个节点即可
			// 这里插入的节点包含的字符是从当前字符开始该字符串剩余的全部字符。
			SuffixNode *node = new SuffixNode();
			string tmp=str.substr(currentIndex,str.length()-currentIndex);
			// 如果当前活动点无子节点，则将新建的节点作为其子节点即可，否则循环遍历子节点(通过兄弟节点进行保存)				string tmp=str.substr(currenctIndex,str.length()-currentIndex);
			node->init(tmp);
			node->iiflag=iflag++;
			SuffixNode* child = activenode->point->Child;
			if (NULL== child) {
				activenode->point->Child = node;
			} else {
				while (NULL!= child->Brother) {
					child = child->Brother;
				}
				child->Brother = node;
			}
		} else {
			// 如果reminder>0，则说明该字符之前存在剩余字符，需要进行分割，然后插入新的后缀字符
			SuffixNode *splitNode = activenode->index;// 待分割的节点即为活动边(active_edge)
			// 创建切分后的节点，放到当前节点的子节点
			// 该节点继承了当前节点的子节点以及后缀节点信息
			SuffixNode *node = new SuffixNode();// 从活动边长度开始截取剩余字符作为子节点,这里从活动边截取，不处理更换活动边的情况
			string tmp=splitNode->str.substr(activenode->length,splitNode->str.length()-activenode->length);
			node->init(tmp);
			node->iiflag=splitNode->iiflag;
			splitNode->iiflag=-1;
			node->Child = splitNode->Child;
			node->suffixNode = splitNode->suffixNode;//后缀节点转移
			splitNode->Child = node;
			splitNode->suffixNode = NULL;
			// 创建新插入的节点，放到当前节点的子节点(通过子节点的兄弟节点保存)
			SuffixNode *newNode = new SuffixNode();// 插入新的后缀字符
			string tmp2=str.substr(currentIndex,str.length()-currentIndex);
			newNode->init(tmp2);
			newNode->iiflag=iflag++;
			splitNode->Child->Brother = newNode;
			splitNode->str = splitNode->str.substr(0,activenode->length);// 修改当前节点的字符
			//以上为一次分割过程。
			// 分割完成之后需根据规则1和规则3进行区分对待
			// 按照规则1进行处理
			if (root == activenode->point) {// 活动节点是根节点的情况
				// activenode->point == root//活动节点保留为根节点
				//activenode->index   root,a,2->root,b,1
			// 按照规则3进行处理
			} else if (NULL== activenode->point->suffixNode) {// 无后缀节点，则活动节点变为root
				activenode->point = root;
			} else {// 否则活动节点变为当前活动节点的后缀节点
				activenode->point = activenode->point->suffixNode;
			}
			// 活动边和活动边长度都重置
			activenode->index =NULL;
			activenode->length = 0;
			// 递归处理剩余的待插入后缀
			Split(str, currentIndex, splitNode);
		}
	}
}

void SuffixTree::Split(string str,int currentIndex,SuffixNode *prefixNode){//相当于把分割部分单独写出来
	// 此处计算剩余待插入的后缀的开始位置，例如剩余后缀数为3，已处理过abx，需要处理ba和x时，下面计算b，相当于新分支节点
	int start=currentIndex-remainder+1;//bx中b的位置
	// dealStart表示本次插入进行查找的开始字符位置（规则二，请看代码首部）
	int a=activenode->point->str.length();//区分后缀节点与root，root时，此值为0
	int b=activenode->length;//和之前length用法类似
	int dealStart=a+b+start;//后缀节点，直接从子节点开始比对，非后缀节点，需要先找出拥有下一个插入字符为首字符的子节点
		// 从dealStart开始查找所有后缀字符是否都存在(相对与活动点)
		for (int index = dealStart; index <= currentIndex; index++) {
			char w =str[index];
			bool f=find(w);
			//以下步骤和create方法中相似
			if (f) {// 存在，则查找下一个，activePoint.length+1，这里不增加reminder
				continue;
			}

			SuffixNode *splitNode = NULL;// 被分割的节点
			if(NULL==activenode->index){// 如果activePoint.index==null，说明没有找到活动边，那么只需要在活动节点下插入一个节点即可
				SuffixNode *node = new SuffixNode();
				int q=str.length()-index;
				string tmp1=str.substr(index,q);
				node->init(tmp1);
				node->iiflag=iflag++;
				SuffixNode *child = activenode->point->Child;
				if(NULL==child){
						activenode->point->Child = node;
					}else{
						while (NULL != child->Brother) {
							child = child->Brother;
						}
						child->Brother = node;
					}
				}else{
					// 开始分割，分割部分同上面的分割
					splitNode = activenode->index;
					// 创建切分后的节点，放到当前节点的子节点
					// 该节点继承了当前节点的子节点以及后缀节点信息
					SuffixNode *node = new SuffixNode();
					string tmp2;
					tmp2=splitNode->str.substr( activenode->length,splitNode->str.length()-activenode->length);
					node->init(tmp2);
					node->iiflag=splitNode->iiflag;//新分裂出的子节点得到原来的iiflag值
					splitNode->iiflag=-1;//原本是叶子节点，因分裂变成非叶子节点，iiflag置-1
					node->Child = splitNode->Child;
					node->suffixNode = splitNode->suffixNode;
					splitNode->Child = node;
					splitNode->suffixNode = NULL;
					// 创建新插入的节点，放到当前节点的子节点(通过子节点的兄弟节点保存)
					SuffixNode *newNode = new SuffixNode();
					string tmp3;
					tmp3=str.substr(index,str.length()-index);
					newNode->init(tmp3);
					newNode->iiflag=iflag++;//新叶子节点
					splitNode->Child->Brother = newNode;
					// 修改当前节点的字符数
					string tmp4;
					tmp4=splitNode->str.substr(0,activenode->length);
					splitNode->str = tmp4;
					// 规则2，连接后缀节点
					prefixNode->suffixNode = splitNode;
				}
				remainder--;

				// 按照规则1进行处理
				if (root == activenode->point) {// 活动节点是根节点的情况
					// activenode->point == root

				// 按照规则3进行处理
				} else if (NULL == activenode->point->suffixNode) {// 无后缀节点，则活动节点变为root
					activenode->point = root;

				} else {
					activenode->point = activenode->point->suffixNode;
				}

				activenode->index =NULL;
				activenode->length = 0;
				if(remainder > 0){// 如果reminder==0则不需要继续递归插入后缀，插入已完成
					Split(str, currentIndex, splitNode);//递归处理即将插入的后缀
				}
			}


}

bool SuffixTree::find(char w){
	const SuffixNode* start=activenode->point;//在活动点处向后寻找。
	 SuffixNode* current=activenode->index;
	 bool exist=false;//是否存在，存在的话，用三元组活动边、活动点等存位置
	if(current==NULL){//current为空，说明无活动边，则在其子节点中进行查找
		//寻找遍历子节点
		SuffixNode* child=start->Child;
		while(child!=NULL){
			if(child->str[0]==w)//存在的话
			{
				activenode->index=child;//在无活动边情况下eg:root,0,0->root,a,1
				activenode->length++;//
				exist=true;
				break;
			}else{
				child=child->Brother;//得以遍历所有的孩子
			}
		}
	}else if(activenode->length!=current->str.length()&&current->str[activenode->length]==w){//有活动边且没有移到活动边末尾
		activenode->length++;
		exist=true;

	}else if(activenode->length==current->str.length()){//有活动边，且此时坐标位置移到活动边末尾，且更换活动节点
//if改activenode-length成remainder,不可以，因为remainder是全局的，而activenode-length会随活动点转移而改变！！！（易错）

		activenode->point=current;
		activenode->index=NULL;
		activenode->length=0;//更换活动点后，activenode-length清0
		SuffixNode* grantchild=current->Child;
		while(grantchild!=NULL){
			if(grantchild->str[0]==w)//存在的话
			{
				activenode->index=grantchild;//在无活动边情况下eg:root,0,0->root,a,1，找到对应的活动边
				activenode->length++;//
				exist=true;
				break;
			}else{
				grantchild=grantchild->Brother;//得以遍历所有的孩子
			}
		}
	}else{
		exist=false;
	}
	return exist;

}

bool SuffixTree::search(string sentence){//O(查询的字符串长度)
	int index = 0;// 查找到的节点的匹配的位置
	// 查找从根节点开始，遍历子节点
	SuffixNode *start = root;
	for (int i = 0; i < sentence.length(); i++) {
		if (start->str.length() < index + 1) {// 如果当前节点已匹配完，则从子节点开始，同时需重置index==0
			index = 0;
			start = start->Child;
			while (NULL != start) {
				// 比较当前节点指定位置(index)的字符是否与待查找字符一致
				// 由于是遍历子节点，所以如果不匹配换个子节点继续
				if (start->str[index] == sentence[i]) {
					index++;
					break;
				} else {
					start = start->Brother;
				}
			}
			if (NULL== start) {// 子节点遍历完都无匹配则返回false
				return false;
			}
		} else if (start->str[index] ==sentence[i]) {
			// 如果当前查找到的节点的还有可比较字符，则进行比较，如果不同则直接返回false
			index++;
		} else {
			return false;
		}
	}
	return true;
}

int SuffixTree::count(string subsen){//遍历所有的节点，找到的时间+数的时间，节点数
	//经过证明, 在最坏情况下, 后缀树的节点数也不会超过2N (N为文本的长度). O(n)
	int index = 0;// 查找到的节点的匹配的位置
	int count=0;//记录相同子串的个数
		// 查找从根节点开始，遍历子节点
		SuffixNode *start = root;
		SuffixNode *child=NULL;//得到当前比对到的节点
		SuffixNode *tmp=NULL;
		for (int i = 0; i < subsen.length(); i++) {

			if (start->str.length() < index + 1) {// 如果当前节点已匹配完，则从子节点开始，同时需重置index==0
				index = 0;
				start = start->Child;
				while (NULL != start) {
					// 比较当前节点指定位置(index)的字符是否与待查找字符一致
					// 由于是遍历子节点，所以如果不匹配换个子节点继续
					if (start->str[index] == subsen[i]) {
						child=start;
						index++;
						break;
					} else {
						start = start->Brother;
					}
				}
				if (NULL== start) {// 子节点遍历完都无匹配则返回false
					return -1;
				}
			} else if (start->str[index] ==subsen[i]) {
				// 如果当前查找到的节点的还有可比较字符，则进行比较，如果不同则直接返回false
				child=start;
				index++;
			} else {
				return -1;
			}
		}
		if(child->Child==NULL)
			return ++count;
		return getleaf(child);
}

string SuffixTree::maxsub(SuffixNode* sn){//最长重复子串O(n)
	if(sn->Child==NULL)//自己为叶子
		return "";
	SuffixNode* tmp=sn->Child;
	int maxlength=0;//记录子串中最长的长度
	string maxstring="";//记录子串中最长的重复子串（最深的非叶节点）
	while(tmp!=NULL){
		string tmpstr=maxsub(tmp);//利用递归方法，求子串中最长的重复子串
		if(tmpstr.length()>maxlength){//如果遇到更长的，则进行更换
			maxlength=tmpstr.length();
			maxstring=tmpstr;
		}//只可以查1个
		tmp=tmp->Brother;
	}
	return sn->str+maxstring;
}

string SuffixTree::maxpub(string s){//O(m+n)构建
	string newword=treeword+s+"#";//形成s=S$S#形式
	string tmp=treeword;
	root->init("");
	activenode->init(root,NULL,0);
	iflag=0;
	int remainder=0;
	create(newword);//构造新的后缀树
	this->print();
	this->treeword=tmp;//搜索时需要用到，因此不能改变treeword的值
	return searchpub(this->root);

}

string SuffixTree::maxreverse(){//O(n)，寻找字符串和字符串反转之间的最长公共子串
	root->init("");
	activenode->init(root,NULL,0);
	iflag=0;
	int remainder=0;
	create(treeword);
	string tmp=treeword.substr(0,treeword.length()-1);
	reverse(tmp.begin(),tmp.end());//反转
	return this->maxpub(tmp);
}

string SuffixTree::searchpub(SuffixNode* sn){//局限，只能两个。合成新子串。。考虑临近叶子子节点和不临近叶子子节点
	//找到最深的且后缀有$#和#的节点
	if(sn->Child==NULL)
		return "";
	else{
		int maxlength=0;
		string maxstring="";
		int sl=0;
		int jing=0;
		SuffixNode* tmp=sn->Child;
		while(tmp!=NULL){
			if(tmp->Child==NULL)//如果为叶子
				if(tmp->iiflag<=treeword.length()-1)
					sl++;
				if(tmp->iiflag>treeword.length()-1)
					jing++;
			if(tmp->iiflag==-3)//不是叶子，子节点有#
				jing++;
			if(tmp->iiflag==-2)//不是叶子，子节点有$
				sl++;
			string tmpstr=searchpub(tmp);
			if(tmpstr.length()>maxlength){
				maxlength=tmpstr.length();
				maxstring=tmpstr;
			}//只可以查1
			tmp=tmp->Brother;
		}
		if(jing!=0&sl==0)//后缀有#
			sn->iiflag=-3;
		if(sl!=0&jing==0)//后缀有$
			sn->iiflag=-2;
		if(sl!=0&jing!=0|maxstring!="")
			return sn->str+maxstring;
		else
			return "";
	}
}

int SuffixTree::getleaf(SuffixNode* sn){//针对所有非叶节点,采用递归
	int leaf=0;
	SuffixNode* tmp=sn->Child;
	while(tmp!=NULL){
		if(tmp->Child==NULL){//孩子是叶子
			leaf++;
		}else{//孩子不是叶子
			leaf+=getleaf(tmp);
		}
		tmp=tmp->Brother;
	}
	return leaf;
}

void SuffixTree::print(){//打印后缀树
	cout<<"[root]"<<endl;
	SuffixNode* child = root->Child;
		while (child != 0) {
				cout<<"|---";
				child->print("    ");
				child = child->Brother;
		}
		cout<<endl;
}
