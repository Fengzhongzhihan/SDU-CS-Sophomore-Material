
/*
 * main.cpp
 *
 *  Created on: 2017��5��1��
 *      Author: lenovo
 */
#include "SuffixTree.h"
#include <list>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "windows.h"
using namespace std;
int main(){
	string act="";//����
	string find="";//��Ѱ�ҵ��ַ���
	string newword="";
	SuffixTree *tree = new SuffixTree();
	cout<<"���������"<<endl;
	cout<<"--������create,�����º�׺��"<<endl;
	cout<<"--������find,���к�׺�����ַ����Ĳ�ѯ"<<endl;
	cout<<"--������count,���к�׺�����ַ����Ĳ�ѯ"<<endl;
	cout<<"--������maxsub,������ظ��Ӵ��Ĳ�ѯ"<<endl;
	cout<<"--������maxpub,����������Ӵ��Ĳ�ѯ"<<endl;
	cout<<"--������reverse,��������ĵĲ�ѯ"<<endl;
	cout<<"--������exit,�˳�"<<endl;
	cout<<"����������";
	cin>>act;
	while(act!="exit"){
//		int start= GetTickCount();
//		clock_t start = clock();
		if(act=="create"){
			cout<<"�������ַ���:";
			string word;
			cin>>word;
			tree->root->init("");
			tree->activenode->init(tree->root,NULL,0);
			tree->iflag=0;
			int remainder=0;
			tree->create(word+"$");
			tree->print();
		}
		else if(act=="find"){
			if(tree->treeword==""){
				cout<<"���ȴ�����׺��==��"<<endl;
				cout<<"�������ַ���:";
				string word;
				cin>>word;
				tree->root->init("");
				tree->activenode->init(tree->root,NULL,0);
				tree->iflag=0;
				int remainder=0;
				tree->create(word+"$");
				tree->print();
			}
			cout<<"��������Ҫ���ҵ��ַ���:";
			cin>>find;
			if(tree->search(find)){
				cout<<"�����Ӵ�"<<endl;
			}else{
				cout<<"�������Ӵ�"<<endl;
			}
		}
		else if(act=="count"){
			if(tree->treeword==""){
				cout<<"���ȴ�����׺��==��"<<endl;
				cout<<"�������ַ���:";
				string word;
				cin>>word;
				tree->root->init("");
				tree->activenode->init(tree->root,NULL,0);
				tree->iflag=0;
				int remainder=0;
				tree->create(word+"$");
				tree->print();
			}
			if(find==""){
				cout<<"��������Ҫ���ҵ��ַ���:";
				cin>>find;
			}
			cout<<"�Ӵ��ظ�����";
			if(tree->count(find)==-1)
				cout<<"�����ڴ��Ӵ�"<<endl;
			else
				cout<<tree->count(find)<<endl;
		}
		else if(act=="maxsub"){
			if(tree->treeword==""){
				cout<<"���ȴ�����׺��==��"<<endl;
				cout<<"�������ַ���:";
				string word;
				cin>>word;
				tree->root->init("");
				tree->activenode->init(tree->root,NULL,0);
				tree->iflag=0;
				int remainder=0;
				tree->create(word+"$");
				tree->print();
			}
			cout<<"��ظ��Ӵ�";
			cout<<tree->maxsub(tree->root)<<endl;
//			int end= GetTickCount();
//					cout <<"Running Time : "<<end - start << endl;
		}
		else if(act=="maxpub"){
			if(tree->treeword==""){
				cout<<"���ȴ�����׺��==��"<<endl;
				cout<<"�������ַ���:";
				string word;
				cin>>word;
				tree->root->init("");
				tree->activenode->init(tree->root,NULL,0);
				tree->iflag=0;
				int remainder=0;
				tree->create(word+"$");
				tree->print();
			}
			cout<<"��������һ���ַ���:";
			cin>>newword;
			string sdw=tree->maxpub(newword);
			if(sdw==""){
				cout<<"�����ڹ����ַ���"<<endl;
			}
			else{
				cout<<sdw<<endl;
			}
			cout<<"�봴�����Ӵ����˳�"<<endl;
		}
		else if(act=="reverse"){
			if(tree->treeword==""){
				cout<<"���ȴ�����׺��==��"<<endl;
				cout<<"�������ַ���:";
				string word;
				cin>>word;
				tree->root->init("");
				tree->activenode->init(tree->root,NULL,0);
				tree->iflag=0;
				int remainder=0;
				tree->create(word+"$");
				tree->print();
//				int end= GetTickCount();
//						cout <<"Running Time : "<<end - start << endl;
			}
			cout<<"������Ӵ�Ϊ��";
			string reverse=tree->maxreverse();

				cout<<reverse<<endl;
				cout<<"�봴�����Ӵ����˳�"<<endl;
		}
		else{
			cout<<"��������ȷ��ʽ������==��"<<endl;
		}
//		int end= GetTickCount();
//				cout <<"Running Time : "<<end - start << endl;
////		clock_t ends = clock();
//		cout <<"Running Time : "<<(double)(ends - start)/ CLOCKS_PER_SEC << endl;
		cout<<"����������:";
		cin>>act;

	}
	cout<<"�ɹ��˳�"<<endl;
	return 0;
}



