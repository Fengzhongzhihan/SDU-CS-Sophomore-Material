
#include <sysinfoapi.h>
#include "SuffixTree.h"
#include "bits/stdc++.h"
using namespace std;
int n ;
SuffixTree *tree = new SuffixTree();
void testMaxPub()  {
    srand((unsigned) time(NULL));
    cin >> n; //ģ�����
    for (int i = 1 ; i <= n; i++) {
        tree->root->init("");
        tree->activenode->init(tree->root,NULL,0);
        tree->iflag=0;
        int remainder=0;
        string word = "";// �̶�һ���ַ���
        string newWord = "abc";
        for (int j = 1 ; j <= i * 100 ; j++) {
            word += "adb";
        }
        tree->create(word+"$");

        clock_t startTime = clock();
        string sdw=tree->maxpub(newWord);
//        if(sdw==""){
//            cout<<"�����ڹ����ַ���"<<endl;
//        }
//        else{
//            cout<<sdw<<endl;
//        }
        clock_t endTime = clock();
        double sumTime = endTime - startTime;
        cout << "Word�ĳ���Ϊ: "<<word.size()<<"; maxpub������ִ��ʱ��Ϊ: " << sumTime/ CLOCKS_PER_SEC * 1000<< "ms; " << endl;
    }
    exit(0);
}
//
int main(){
    testMaxPub();
    string act="";//����
    cout<<"���������"<<endl;
    cout<<"--������create,�����º�׺��"<<endl;
    cout<<"--������find,���к�׺�����ַ����Ĳ�ѯ"<<endl;
    cout<<"--������count,���к�׺�����ַ����Ĳ�ѯ"<<endl;
    cout<<"--������maxsub,������ظ��Ӵ��Ĳ�ѯ"<<endl;
    //���������㷨��ʱ�临�Ӷ�
    cout<<"--������maxpub,����������Ӵ��Ĳ�ѯ"<<endl; // ͨ�������֤
    cout<<"--������exit,�˳�"<<endl;
    cout<<"����������";
    cin>>act;
    while(act!="exit"){
        string find = "";
        if(act=="create"){
            cout<<"��������Ҫ������׺�����ַ���:";
            string word;
            cin>>word;
            tree->root->init(""); // ��ʼ�����ڵ�
            tree->activenode->init(tree->root,NULL,0); // ��ʼ����ڵ�
            tree->iflag=0;
            int remainder=0;
            tree->create(word + "$"); // ��$����β
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
                if(tree->count(find)==-1)
                    cout<<"�����ڴ��Ӵ�"<<endl;
                else
                    cout<<"�Ӵ��ظ�����" << tree->count(find)<<endl;
            }
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
            string newWord;
            cout<<"��������һ���ַ���:";
            cin >> newWord;
            string sdw=tree->maxpub(newWord);
            if(sdw==""){
                cout<<"�����ڹ����ַ���"<<endl;
            }
            else{
                cout<<sdw<<endl;
            }
            cout<<"�봴�����Ӵ����˳�"<<endl;
        }
        else{
            cout<<"��������ȷ��ʽ������==��"<<endl;
        }

        cout<<"����������:";
        cin>>act;
    }
    cout<<"�ɹ��˳�"<<endl;
    return 0;
}




