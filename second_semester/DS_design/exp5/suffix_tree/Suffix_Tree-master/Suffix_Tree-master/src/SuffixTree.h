/*
 * SuffixTree.h
 *
 *  Created on: 2017年4月25日
 *      Author: lenovo
 */

#ifndef SUFFIXTREE_H_
#define SUFFIXTREE_H_
#include <list>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;


struct SuffixNode
{
public:
    SuffixNode* Child; //左孩子，子节点,如果为iiflag=-1,说明是非叶子节点;
//    iiflag=-3,不是叶子，子树中存在叶子节点含有#;iiflag=-2,不是叶子，子树中存在叶子节点含有$#;
    SuffixNode* Brother; //右兄弟（右孩子）
    SuffixNode* suffixNode;//后缀链接

    string str;//节点上对应字符串
    int iiflag;//叶子节点：对应字符串开始位置；其它：标识子节点中是否有$、#(用于回文)
public:
    void init(string str)//用于初始化的方法
        {
            this->str=str;
    		Child = 0;
    		Brother=0;
            iiflag=-1;
//            tmpp=0;

        }
    void print(string s){//打印函数
    	cout<<this->str;
    	if(Child==NULL){//如果是叶子节点，打印对应字符串开始的位置
            cout<<"   ";
            cout<<"||"<<this->iiflag;}
    		cout<<endl;

    	SuffixNode* tmpp=Child;
    	while (0!= tmpp) {
    			cout<<s<<"|---";
    			string tmp=s+s;
    			tmpp->print(tmp);//运用递归方法打印以此叶子为根节点的整颗树
    			tmpp =tmpp->Brother;
    	}
    }
};
/*
* 活动点(active point)，一个三元组：(active_node,active_edge,active_length)
*/
struct ActiveNode{
public:
	SuffixNode* point;//活动点
	SuffixNode* index;//活动边
	int length;//活动边长度

public:
	void init(SuffixNode* point,SuffixNode* index,int length){//初始化方法
		this->point=point;
		this->index=index;
		this->length=length;
	}
};

class SuffixTree {
public:
	SuffixTree();
	~SuffixTree();
	void create(string str);//构建后缀树
	void Split(string str,int currentIndex,SuffixNode *prefixNode);
	//处理剩余的等待插入的后缀
	bool find(char w);//寻找当前活动点子节点中是否包括后缀字符的节点（边）
	bool search(string sentence);//查找给定字符串是否为其子串
	void print();//打印后缀树
	int  count(string subsen);//查找字符串中出现字符串subsen的次数
	string maxsub(SuffixNode* sn);//寻找最长的重复子串
	string maxpub(string s);//寻找同s的最长公共子串
	string searchpub(SuffixNode* sn);//寻找两个子串中最长公共子串
	string maxreverse();//寻找回文子串
	int getleaf(SuffixNode* sn);//得到某节点的叶子数
public:
	SuffixNode* root =new SuffixNode();//根节点
	ActiveNode* activenode=new ActiveNode();//当前活动点，活动边在这里用节点表示
	int remainder=0;//剩余后缀树，即需要插入多少后缀
	int iflag=0;//记录当前后缀树的节点
	string treeword="";//后缀树表示的字符串。
};

#endif /* SUFFIXTREE_H_ */
