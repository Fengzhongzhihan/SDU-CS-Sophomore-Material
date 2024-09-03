
/*
 * main.cpp
 *
 *  Created on: 2017年5月1日
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
	string act="";//命令
	string find="";//待寻找的字符串
	string newword="";
	SuffixTree *tree = new SuffixTree();
	cout<<"请输入命令："<<endl;
	cout<<"--》输入create,创建新后缀树"<<endl;
	cout<<"--》输入find,进行后缀树中字符串的查询"<<endl;
	cout<<"--》输入count,进行后缀树中字符串的查询"<<endl;
	cout<<"--》输入maxsub,进行最长重复子串的查询"<<endl;
	cout<<"--》输入maxpub,进行最长公共子串的查询"<<endl;
	cout<<"--》输入reverse,进行最长回文的查询"<<endl;
	cout<<"--》输入exit,退出"<<endl;
	cout<<"请输入命令";
	cin>>act;
	while(act!="exit"){
//		int start= GetTickCount();
//		clock_t start = clock();
		if(act=="create"){
			cout<<"请输入字符串:";
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
				cout<<"请先创建后缀树==》"<<endl;
				cout<<"请输入字符串:";
				string word;
				cin>>word;
				tree->root->init("");
				tree->activenode->init(tree->root,NULL,0);
				tree->iflag=0;
				int remainder=0;
				tree->create(word+"$");
				tree->print();
			}
			cout<<"请输入想要查找的字符串:";
			cin>>find;
			if(tree->search(find)){
				cout<<"存在子串"<<endl;
			}else{
				cout<<"不存在子串"<<endl;
			}
		}
		else if(act=="count"){
			if(tree->treeword==""){
				cout<<"请先创建后缀树==》"<<endl;
				cout<<"请输入字符串:";
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
				cout<<"请输入想要查找的字符串:";
				cin>>find;
			}
			cout<<"子串重复个数";
			if(tree->count(find)==-1)
				cout<<"不存在此子串"<<endl;
			else
				cout<<tree->count(find)<<endl;
		}
		else if(act=="maxsub"){
			if(tree->treeword==""){
				cout<<"请先创建后缀树==》"<<endl;
				cout<<"请输入字符串:";
				string word;
				cin>>word;
				tree->root->init("");
				tree->activenode->init(tree->root,NULL,0);
				tree->iflag=0;
				int remainder=0;
				tree->create(word+"$");
				tree->print();
			}
			cout<<"最长重复子串";
			cout<<tree->maxsub(tree->root)<<endl;
//			int end= GetTickCount();
//					cout <<"Running Time : "<<end - start << endl;
		}
		else if(act=="maxpub"){
			if(tree->treeword==""){
				cout<<"请先创建后缀树==》"<<endl;
				cout<<"请输入字符串:";
				string word;
				cin>>word;
				tree->root->init("");
				tree->activenode->init(tree->root,NULL,0);
				tree->iflag=0;
				int remainder=0;
				tree->create(word+"$");
				tree->print();
			}
			cout<<"请输入另一个字符串:";
			cin>>newword;
			string sdw=tree->maxpub(newword);
			if(sdw==""){
				cout<<"不存在公共字符串"<<endl;
			}
			else{
				cout<<sdw<<endl;
			}
			cout<<"请创建新子串或退出"<<endl;
		}
		else if(act=="reverse"){
			if(tree->treeword==""){
				cout<<"请先创建后缀树==》"<<endl;
				cout<<"请输入字符串:";
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
			cout<<"最长回文子串为：";
			string reverse=tree->maxreverse();

				cout<<reverse<<endl;
				cout<<"请创建新子串或退出"<<endl;
		}
		else{
			cout<<"请输入正确形式的命令==》"<<endl;
		}
//		int end= GetTickCount();
//				cout <<"Running Time : "<<end - start << endl;
////		clock_t ends = clock();
//		cout <<"Running Time : "<<(double)(ends - start)/ CLOCKS_PER_SEC << endl;
		cout<<"请输入命令:";
		cin>>act;

	}
	cout<<"成功退出"<<endl;
	return 0;
}



