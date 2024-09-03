#include<bits/stdc++.h>
using namespace std;
//使用set来处理noteBook
set <string> noteBook;
int m;

//查单词
bool findWord (string str) {
    //找到了  O(logm)
    if (noteBook.find(str) != noteBook.end()) {
        cout << "found" << endl;
    }
    //没找到, 写入单词
    else {
        noteBook.insert(str);
        cout << "write" << endl;
    }
}

bool eraseWord (string str) {
    //找到了, 删除单词, O(logm)
    if (noteBook.find(str) != noteBook.end()) {
        noteBook.erase(str);
        cout << "erased" << endl;
    }   
    //没找到
    else {
        cout << "not found " << endl;
    }
}

void printWord () {
    //按照字典序顺序输出, O(m)
    for (set <string> :: iterator it =noteBook.begin(); it != noteBook.end(); it ++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    cin >> m;
    while (m--) {
        int op;
        string str;
        cin >> op;
        //根据输入的操作进行操作, 时间复杂度为O(m^2)
        if (op == 1) {
            cin >> str;
            findWord(str);
        }
        else if (op == 2) {
            cin >> str;
            eraseWord(str);
        }
        else {
            printWord();
        }
    }

    return 0;
}