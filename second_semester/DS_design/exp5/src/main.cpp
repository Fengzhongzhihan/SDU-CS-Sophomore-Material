
#include <sysinfoapi.h>
#include "SuffixTree.h"
#include "bits/stdc++.h"
using namespace std;
int n ;
SuffixTree *tree = new SuffixTree();
void testMaxPub()  {
    srand((unsigned) time(NULL));
    cin >> n; //模拟次数
    for (int i = 1 ; i <= n; i++) {
        tree->root->init("");
        tree->activenode->init(tree->root,NULL,0);
        tree->iflag=0;
        int remainder=0;
        string word = "";// 固定一个字符串
        string newWord = "abc";
        for (int j = 1 ; j <= i * 100 ; j++) {
            word += "adb";
        }
        tree->create(word+"$");

        clock_t startTime = clock();
        string sdw=tree->maxpub(newWord);
//        if(sdw==""){
//            cout<<"不存在公共字符串"<<endl;
//        }
//        else{
//            cout<<sdw<<endl;
//        }
        clock_t endTime = clock();
        double sumTime = endTime - startTime;
        cout << "Word的长度为: "<<word.size()<<"; maxpub函数总执行时间为: " << sumTime/ CLOCKS_PER_SEC * 1000<< "ms; " << endl;
    }
    exit(0);
}
//
int main(){
    testMaxPub();
    string act="";//命令
    cout<<"请输入命令："<<endl;
    cout<<"--》输入create,创建新后缀树"<<endl;
    cout<<"--》输入find,进行后缀树中字符串的查询"<<endl;
    cout<<"--》输入count,进行后缀树中字符串的查询"<<endl;
    cout<<"--》输入maxsub,进行最长重复子串的查询"<<endl;
    //分析以上算法的时间复杂度
    cout<<"--》输入maxpub,进行最长公共子串的查询"<<endl; // 通过结果验证
    cout<<"--》输入exit,退出"<<endl;
    cout<<"请输入命令";
    cin>>act;
    while(act!="exit"){
        string find = "";
        if(act=="create"){
            cout<<"请输入需要创建后缀树的字符串:";
            string word;
            cin>>word;
            tree->root->init(""); // 初始化根节点
            tree->activenode->init(tree->root,NULL,0); // 初始化活动节点
            tree->iflag=0;
            int remainder=0;
            tree->create(word + "$"); // 以$符结尾
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
                if(tree->count(find)==-1)
                    cout<<"不存在此子串"<<endl;
                else
                    cout<<"子串重复个数" << tree->count(find)<<endl;
            }
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
            string newWord;
            cout<<"请输入另一个字符串:";
            cin >> newWord;
            string sdw=tree->maxpub(newWord);
            if(sdw==""){
                cout<<"不存在公共字符串"<<endl;
            }
            else{
                cout<<sdw<<endl;
            }
            cout<<"请创建新子串或退出"<<endl;
        }
        else{
            cout<<"请输入正确形式的命令==》"<<endl;
        }

        cout<<"请输入命令:";
        cin>>act;
    }
    cout<<"成功退出"<<endl;
    return 0;
}




