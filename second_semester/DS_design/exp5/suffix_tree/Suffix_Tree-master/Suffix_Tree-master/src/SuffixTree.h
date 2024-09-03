/*
 * SuffixTree.h
 *
 *  Created on: 2017��4��25��
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
    SuffixNode* Child; //���ӣ��ӽڵ�,���Ϊiiflag=-1,˵���Ƿ�Ҷ�ӽڵ�;
//    iiflag=-3,����Ҷ�ӣ������д���Ҷ�ӽڵ㺬��#;iiflag=-2,����Ҷ�ӣ������д���Ҷ�ӽڵ㺬��$#;
    SuffixNode* Brother; //���ֵܣ��Һ��ӣ�
    SuffixNode* suffixNode;//��׺����

    string str;//�ڵ��϶�Ӧ�ַ���
    int iiflag;//Ҷ�ӽڵ㣺��Ӧ�ַ�����ʼλ�ã���������ʶ�ӽڵ����Ƿ���$��#(���ڻ���)
public:
    void init(string str)//���ڳ�ʼ���ķ���
        {
            this->str=str;
    		Child = 0;
    		Brother=0;
            iiflag=-1;
//            tmpp=0;

        }
    void print(string s){//��ӡ����
    	cout<<this->str;
    	if(Child==NULL){//�����Ҷ�ӽڵ㣬��ӡ��Ӧ�ַ�����ʼ��λ��
            cout<<"   ";
            cout<<"||"<<this->iiflag;}
    		cout<<endl;

    	SuffixNode* tmpp=Child;
    	while (0!= tmpp) {
    			cout<<s<<"|---";
    			string tmp=s+s;
    			tmpp->print(tmp);//���õݹ鷽����ӡ�Դ�Ҷ��Ϊ���ڵ��������
    			tmpp =tmpp->Brother;
    	}
    }
};
/*
* ���(active point)��һ����Ԫ�飺(active_node,active_edge,active_length)
*/
struct ActiveNode{
public:
	SuffixNode* point;//���
	SuffixNode* index;//���
	int length;//��߳���

public:
	void init(SuffixNode* point,SuffixNode* index,int length){//��ʼ������
		this->point=point;
		this->index=index;
		this->length=length;
	}
};

class SuffixTree {
public:
	SuffixTree();
	~SuffixTree();
	void create(string str);//������׺��
	void Split(string str,int currentIndex,SuffixNode *prefixNode);
	//����ʣ��ĵȴ�����ĺ�׺
	bool find(char w);//Ѱ�ҵ�ǰ����ӽڵ����Ƿ������׺�ַ��Ľڵ㣨�ߣ�
	bool search(string sentence);//���Ҹ����ַ����Ƿ�Ϊ���Ӵ�
	void print();//��ӡ��׺��
	int  count(string subsen);//�����ַ����г����ַ���subsen�Ĵ���
	string maxsub(SuffixNode* sn);//Ѱ������ظ��Ӵ�
	string maxpub(string s);//Ѱ��ͬs��������Ӵ�
	string searchpub(SuffixNode* sn);//Ѱ�������Ӵ���������Ӵ�
	string maxreverse();//Ѱ�һ����Ӵ�
	int getleaf(SuffixNode* sn);//�õ�ĳ�ڵ��Ҷ����
public:
	SuffixNode* root =new SuffixNode();//���ڵ�
	ActiveNode* activenode=new ActiveNode();//��ǰ��㣬����������ýڵ��ʾ
	int remainder=0;//ʣ���׺��������Ҫ������ٺ�׺
	int iflag=0;//��¼��ǰ��׺���Ľڵ�
	string treeword="";//��׺����ʾ���ַ�����
};

#endif /* SUFFIXTREE_H_ */
