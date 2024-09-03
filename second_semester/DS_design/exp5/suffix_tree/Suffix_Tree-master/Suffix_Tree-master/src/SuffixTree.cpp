/*
 * SuffixTree.cpp
 *
 *  Created on: 2017��4��25��
 *      Author: lenovo
 */
/*
 * ��¼��ǰ��������Ԫ��
 *    ��Ԫ�飬  active-node����ǰ�����Ľڵ�
 *          active-edge������δ����Ҫ������ַ���������ĸ
 *	        active-length������δ����Ҫ������ַ����ĳ��ȡ�
 *          ��ʼΪ root,0,0
 *    ����1��
 *������ڵ����ӽڵ�����׺����ѭ��
 *active_node ����Ϊ root��
 *active_edge ������Ϊ������������º�׺�����ַ���
 *active_length �� 1��
 *    ����2��
 *������Ƿ��ѣ�Split��һ���߲��Ҳ��루Insert��һ���µĽڵ㣬
 *����������½ڵ㲻�ǵ�ǰ�����д����ĵ�һ���ڵ㣬
 *����ǰ����Ľڵ�����½ڵ�ͨ��һ�������ָ�����ӣ�
 *��Ϊ��׺���ӣ�Suffix Link������׺����ͨ��һ����������ʾ��
 *    ����3��
 *���� active_node ��Ϊ root �Ľڵ���ѱ�ʱ��
 *�������ź�׺���ӣ�Suffix Link���ķ���Ѱ�ҽڵ㣬
 *�����øýڵ�Ϊ active_node����������ڣ������� active_node Ϊ root��
 *active_edge �� active_length ���ֲ��䡣
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
	//��ʼ��

	root->init("");
	activenode->init(root,NULL,0);

}

SuffixTree::~SuffixTree() {
	// TODO Auto-generated destructor stub
}

void SuffixTree::create(string str){//���ַ���str�����׺��
	int index = 0;//
	treeword=str;
	while (index < str.length()) {// ѭ��������׺

		int currentIndex = index++;// ���浱ǰ��λ��
		char w =str[currentIndex];// �õ���ǰ�ĺ�׺�ַ�
		bool f=find(w);
		if (f) {// �����Ƿ���ڱ����е�ǰ��׺�ַ��Ľڵ�
			remainder++;// ���ڣ���reminder+1��activenode->length+1����������ѭ��
			continue;//��������ѭ�������ҵ�һ����ͬ����find���������û���¼һ�Σ��ݲ�����
		}else if(!f&&!activenode->index&&remainder != 0){
			//�Ҳ����Ҵ�ʱindex=0������Ҫ�����׺��remainder=0�������ת�Ƶ������
			SuffixNode* child=activenode->point->Child;
			SuffixNode* splitNode=activenode->point;
			SuffixNode *newNode=new SuffixNode();//��������Ľڵ�
			string s=str.substr(currentIndex,str.length()-currentIndex);//�����ѵ��ַ�
			newNode->init(s);
			newNode->iiflag=iflag++;//newNodeΪ�½�����Ҷ�ӽڵ㣬��Ӧ���ַ�����ʼλ��
			//������ڵ㺢�ӵ��ֵܽڵ㣬�嵽���
			while(child->Brother!=NULL){
				child=child->Brother;
			}
			child->Brother=newNode;
			//����Ϊһ�ηָ���̡�
			// �ٷ�root�ڵ��Ͻ��в������ָ����֮������ݹ���3�Դ�
			if (NULL== activenode->point->suffixNode) {// �޺�׺�ڵ㣬���ڵ��Ϊroot
				activenode->point = root;
			} else {// �����ڵ��Ϊ��ǰ��ڵ�ĺ�׺�ڵ�
				activenode->point = activenode->point->suffixNode;
			}
				activenode->index=NULL;
				activenode->length=0;
				Split(str, currentIndex, splitNode);//eg:��Ҫ����abx,bx,x,������abx������Ҫ��������bx�����з��Ѳ���
				continue;
		}

		// �����ڵĻ������reminder==0��ʾ֮ǰ�ڸ��ַ�֮ǰδʣ��������������ĺ�׺�ַ�������ֱ�Ӳ���ú�׺�ַ�����
		if (remainder == 0) {
			// ֱ���ڵ�ǰ��ڵ����һ���ڵ㼴��
			// �������Ľڵ�������ַ��Ǵӵ�ǰ�ַ���ʼ���ַ���ʣ���ȫ���ַ���
			SuffixNode *node = new SuffixNode();
			string tmp=str.substr(currentIndex,str.length()-currentIndex);
			// �����ǰ������ӽڵ㣬���½��Ľڵ���Ϊ���ӽڵ㼴�ɣ�����ѭ�������ӽڵ�(ͨ���ֵܽڵ���б���)				string tmp=str.substr(currenctIndex,str.length()-currentIndex);
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
			// ���reminder>0����˵�����ַ�֮ǰ����ʣ���ַ�����Ҫ���зָȻ������µĺ�׺�ַ�
			SuffixNode *splitNode = activenode->index;// ���ָ�Ľڵ㼴Ϊ���(active_edge)
			// �����зֺ�Ľڵ㣬�ŵ���ǰ�ڵ���ӽڵ�
			// �ýڵ�̳��˵�ǰ�ڵ���ӽڵ��Լ���׺�ڵ���Ϣ
			SuffixNode *node = new SuffixNode();// �ӻ�߳��ȿ�ʼ��ȡʣ���ַ���Ϊ�ӽڵ�,����ӻ�߽�ȡ�������������ߵ����
			string tmp=splitNode->str.substr(activenode->length,splitNode->str.length()-activenode->length);
			node->init(tmp);
			node->iiflag=splitNode->iiflag;
			splitNode->iiflag=-1;
			node->Child = splitNode->Child;
			node->suffixNode = splitNode->suffixNode;//��׺�ڵ�ת��
			splitNode->Child = node;
			splitNode->suffixNode = NULL;
			// �����²���Ľڵ㣬�ŵ���ǰ�ڵ���ӽڵ�(ͨ���ӽڵ���ֵܽڵ㱣��)
			SuffixNode *newNode = new SuffixNode();// �����µĺ�׺�ַ�
			string tmp2=str.substr(currentIndex,str.length()-currentIndex);
			newNode->init(tmp2);
			newNode->iiflag=iflag++;
			splitNode->Child->Brother = newNode;
			splitNode->str = splitNode->str.substr(0,activenode->length);// �޸ĵ�ǰ�ڵ���ַ�
			//����Ϊһ�ηָ���̡�
			// �ָ����֮������ݹ���1�͹���3�������ֶԴ�
			// ���չ���1���д���
			if (root == activenode->point) {// ��ڵ��Ǹ��ڵ�����
				// activenode->point == root//��ڵ㱣��Ϊ���ڵ�
				//activenode->index   root,a,2->root,b,1
			// ���չ���3���д���
			} else if (NULL== activenode->point->suffixNode) {// �޺�׺�ڵ㣬���ڵ��Ϊroot
				activenode->point = root;
			} else {// �����ڵ��Ϊ��ǰ��ڵ�ĺ�׺�ڵ�
				activenode->point = activenode->point->suffixNode;
			}
			// ��ߺͻ�߳��ȶ�����
			activenode->index =NULL;
			activenode->length = 0;
			// �ݹ鴦��ʣ��Ĵ������׺
			Split(str, currentIndex, splitNode);
		}
	}
}

void SuffixTree::Split(string str,int currentIndex,SuffixNode *prefixNode){//�൱�ڰѷָ�ֵ���д����
	// �˴�����ʣ�������ĺ�׺�Ŀ�ʼλ�ã�����ʣ���׺��Ϊ3���Ѵ����abx����Ҫ����ba��xʱ���������b���൱���·�֧�ڵ�
	int start=currentIndex-remainder+1;//bx��b��λ��
	// dealStart��ʾ���β�����в��ҵĿ�ʼ�ַ�λ�ã���������뿴�����ײ���
	int a=activenode->point->str.length();//���ֺ�׺�ڵ���root��rootʱ����ֵΪ0
	int b=activenode->length;//��֮ǰlength�÷�����
	int dealStart=a+b+start;//��׺�ڵ㣬ֱ�Ӵ��ӽڵ㿪ʼ�ȶԣ��Ǻ�׺�ڵ㣬��Ҫ���ҳ�ӵ����һ�������ַ�Ϊ���ַ����ӽڵ�
		// ��dealStart��ʼ�������к�׺�ַ��Ƿ񶼴���(�������)
		for (int index = dealStart; index <= currentIndex; index++) {
			char w =str[index];
			bool f=find(w);
			//���²����create����������
			if (f) {// ���ڣ��������һ����activePoint.length+1�����ﲻ����reminder
				continue;
			}

			SuffixNode *splitNode = NULL;// ���ָ�Ľڵ�
			if(NULL==activenode->index){// ���activePoint.index==null��˵��û���ҵ���ߣ���ôֻ��Ҫ�ڻ�ڵ��²���һ���ڵ㼴��
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
					// ��ʼ�ָ�ָ��ͬ����ķָ�
					splitNode = activenode->index;
					// �����зֺ�Ľڵ㣬�ŵ���ǰ�ڵ���ӽڵ�
					// �ýڵ�̳��˵�ǰ�ڵ���ӽڵ��Լ���׺�ڵ���Ϣ
					SuffixNode *node = new SuffixNode();
					string tmp2;
					tmp2=splitNode->str.substr( activenode->length,splitNode->str.length()-activenode->length);
					node->init(tmp2);
					node->iiflag=splitNode->iiflag;//�·��ѳ����ӽڵ�õ�ԭ����iiflagֵ
					splitNode->iiflag=-1;//ԭ����Ҷ�ӽڵ㣬����ѱ�ɷ�Ҷ�ӽڵ㣬iiflag��-1
					node->Child = splitNode->Child;
					node->suffixNode = splitNode->suffixNode;
					splitNode->Child = node;
					splitNode->suffixNode = NULL;
					// �����²���Ľڵ㣬�ŵ���ǰ�ڵ���ӽڵ�(ͨ���ӽڵ���ֵܽڵ㱣��)
					SuffixNode *newNode = new SuffixNode();
					string tmp3;
					tmp3=str.substr(index,str.length()-index);
					newNode->init(tmp3);
					newNode->iiflag=iflag++;//��Ҷ�ӽڵ�
					splitNode->Child->Brother = newNode;
					// �޸ĵ�ǰ�ڵ���ַ���
					string tmp4;
					tmp4=splitNode->str.substr(0,activenode->length);
					splitNode->str = tmp4;
					// ����2�����Ӻ�׺�ڵ�
					prefixNode->suffixNode = splitNode;
				}
				remainder--;

				// ���չ���1���д���
				if (root == activenode->point) {// ��ڵ��Ǹ��ڵ�����
					// activenode->point == root

				// ���չ���3���д���
				} else if (NULL == activenode->point->suffixNode) {// �޺�׺�ڵ㣬���ڵ��Ϊroot
					activenode->point = root;

				} else {
					activenode->point = activenode->point->suffixNode;
				}

				activenode->index =NULL;
				activenode->length = 0;
				if(remainder > 0){// ���reminder==0����Ҫ�����ݹ�����׺�����������
					Split(str, currentIndex, splitNode);//�ݹ鴦��������ĺ�׺
				}
			}


}

bool SuffixTree::find(char w){
	const SuffixNode* start=activenode->point;//�ڻ�㴦���Ѱ�ҡ�
	 SuffixNode* current=activenode->index;
	 bool exist=false;//�Ƿ���ڣ����ڵĻ�������Ԫ���ߡ����ȴ�λ��
	if(current==NULL){//currentΪ�գ�˵���޻�ߣ��������ӽڵ��н��в���
		//Ѱ�ұ����ӽڵ�
		SuffixNode* child=start->Child;
		while(child!=NULL){
			if(child->str[0]==w)//���ڵĻ�
			{
				activenode->index=child;//���޻�������eg:root,0,0->root,a,1
				activenode->length++;//
				exist=true;
				break;
			}else{
				child=child->Brother;//���Ա������еĺ���
			}
		}
	}else if(activenode->length!=current->str.length()&&current->str[activenode->length]==w){//�л����û���Ƶ����ĩβ
		activenode->length++;
		exist=true;

	}else if(activenode->length==current->str.length()){//�л�ߣ��Ҵ�ʱ����λ���Ƶ����ĩβ���Ҹ�����ڵ�
//if��activenode-length��remainder,�����ԣ���Ϊremainder��ȫ�ֵģ���activenode-length������ת�ƶ��ı䣡�������״�

		activenode->point=current;
		activenode->index=NULL;
		activenode->length=0;//��������activenode-length��0
		SuffixNode* grantchild=current->Child;
		while(grantchild!=NULL){
			if(grantchild->str[0]==w)//���ڵĻ�
			{
				activenode->index=grantchild;//���޻�������eg:root,0,0->root,a,1���ҵ���Ӧ�Ļ��
				activenode->length++;//
				exist=true;
				break;
			}else{
				grantchild=grantchild->Brother;//���Ա������еĺ���
			}
		}
	}else{
		exist=false;
	}
	return exist;

}

bool SuffixTree::search(string sentence){//O(��ѯ���ַ�������)
	int index = 0;// ���ҵ��Ľڵ��ƥ���λ��
	// ���ҴӸ��ڵ㿪ʼ�������ӽڵ�
	SuffixNode *start = root;
	for (int i = 0; i < sentence.length(); i++) {
		if (start->str.length() < index + 1) {// �����ǰ�ڵ���ƥ���꣬����ӽڵ㿪ʼ��ͬʱ������index==0
			index = 0;
			start = start->Child;
			while (NULL != start) {
				// �Ƚϵ�ǰ�ڵ�ָ��λ��(index)���ַ��Ƿ���������ַ�һ��
				// �����Ǳ����ӽڵ㣬���������ƥ�任���ӽڵ����
				if (start->str[index] == sentence[i]) {
					index++;
					break;
				} else {
					start = start->Brother;
				}
			}
			if (NULL== start) {// �ӽڵ�����궼��ƥ���򷵻�false
				return false;
			}
		} else if (start->str[index] ==sentence[i]) {
			// �����ǰ���ҵ��Ľڵ�Ļ��пɱȽ��ַ�������бȽϣ������ͬ��ֱ�ӷ���false
			index++;
		} else {
			return false;
		}
	}
	return true;
}

int SuffixTree::count(string subsen){//�������еĽڵ㣬�ҵ���ʱ��+����ʱ�䣬�ڵ���
	//����֤��, ��������, ��׺���Ľڵ���Ҳ���ᳬ��2N (NΪ�ı��ĳ���). O(n)
	int index = 0;// ���ҵ��Ľڵ��ƥ���λ��
	int count=0;//��¼��ͬ�Ӵ��ĸ���
		// ���ҴӸ��ڵ㿪ʼ�������ӽڵ�
		SuffixNode *start = root;
		SuffixNode *child=NULL;//�õ���ǰ�ȶԵ��Ľڵ�
		SuffixNode *tmp=NULL;
		for (int i = 0; i < subsen.length(); i++) {

			if (start->str.length() < index + 1) {// �����ǰ�ڵ���ƥ���꣬����ӽڵ㿪ʼ��ͬʱ������index==0
				index = 0;
				start = start->Child;
				while (NULL != start) {
					// �Ƚϵ�ǰ�ڵ�ָ��λ��(index)���ַ��Ƿ���������ַ�һ��
					// �����Ǳ����ӽڵ㣬���������ƥ�任���ӽڵ����
					if (start->str[index] == subsen[i]) {
						child=start;
						index++;
						break;
					} else {
						start = start->Brother;
					}
				}
				if (NULL== start) {// �ӽڵ�����궼��ƥ���򷵻�false
					return -1;
				}
			} else if (start->str[index] ==subsen[i]) {
				// �����ǰ���ҵ��Ľڵ�Ļ��пɱȽ��ַ�������бȽϣ������ͬ��ֱ�ӷ���false
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

string SuffixTree::maxsub(SuffixNode* sn){//��ظ��Ӵ�O(n)
	if(sn->Child==NULL)//�Լ�ΪҶ��
		return "";
	SuffixNode* tmp=sn->Child;
	int maxlength=0;//��¼�Ӵ�����ĳ���
	string maxstring="";//��¼�Ӵ�������ظ��Ӵ�������ķ�Ҷ�ڵ㣩
	while(tmp!=NULL){
		string tmpstr=maxsub(tmp);//���õݹ鷽�������Ӵ�������ظ��Ӵ�
		if(tmpstr.length()>maxlength){//������������ģ�����и���
			maxlength=tmpstr.length();
			maxstring=tmpstr;
		}//ֻ���Բ�1��
		tmp=tmp->Brother;
	}
	return sn->str+maxstring;
}

string SuffixTree::maxpub(string s){//O(m+n)����
	string newword=treeword+s+"#";//�γ�s=S$S#��ʽ
	string tmp=treeword;
	root->init("");
	activenode->init(root,NULL,0);
	iflag=0;
	int remainder=0;
	create(newword);//�����µĺ�׺��
	this->print();
	this->treeword=tmp;//����ʱ��Ҫ�õ�����˲��ܸı�treeword��ֵ
	return searchpub(this->root);

}

string SuffixTree::maxreverse(){//O(n)��Ѱ���ַ������ַ�����ת֮���������Ӵ�
	root->init("");
	activenode->init(root,NULL,0);
	iflag=0;
	int remainder=0;
	create(treeword);
	string tmp=treeword.substr(0,treeword.length()-1);
	reverse(tmp.begin(),tmp.end());//��ת
	return this->maxpub(tmp);
}

string SuffixTree::searchpub(SuffixNode* sn){//���ޣ�ֻ���������ϳ����Ӵ����������ٽ�Ҷ���ӽڵ�Ͳ��ٽ�Ҷ���ӽڵ�
	//�ҵ�������Һ�׺��$#��#�Ľڵ�
	if(sn->Child==NULL)
		return "";
	else{
		int maxlength=0;
		string maxstring="";
		int sl=0;
		int jing=0;
		SuffixNode* tmp=sn->Child;
		while(tmp!=NULL){
			if(tmp->Child==NULL)//���ΪҶ��
				if(tmp->iiflag<=treeword.length()-1)
					sl++;
				if(tmp->iiflag>treeword.length()-1)
					jing++;
			if(tmp->iiflag==-3)//����Ҷ�ӣ��ӽڵ���#
				jing++;
			if(tmp->iiflag==-2)//����Ҷ�ӣ��ӽڵ���$
				sl++;
			string tmpstr=searchpub(tmp);
			if(tmpstr.length()>maxlength){
				maxlength=tmpstr.length();
				maxstring=tmpstr;
			}//ֻ���Բ�1
			tmp=tmp->Brother;
		}
		if(jing!=0&sl==0)//��׺��#
			sn->iiflag=-3;
		if(sl!=0&jing==0)//��׺��$
			sn->iiflag=-2;
		if(sl!=0&jing!=0|maxstring!="")
			return sn->str+maxstring;
		else
			return "";
	}
}

int SuffixTree::getleaf(SuffixNode* sn){//������з�Ҷ�ڵ�,���õݹ�
	int leaf=0;
	SuffixNode* tmp=sn->Child;
	while(tmp!=NULL){
		if(tmp->Child==NULL){//������Ҷ��
			leaf++;
		}else{//���Ӳ���Ҷ��
			leaf+=getleaf(tmp);
		}
		tmp=tmp->Brother;
	}
	return leaf;
}

void SuffixTree::print(){//��ӡ��׺��
	cout<<"[root]"<<endl;
	SuffixNode* child = root->Child;
		while (child != 0) {
				cout<<"|---";
				child->print("    ");
				child = child->Brother;
		}
		cout<<endl;
}
