//
// Created by Lenovo on 2024-04-26.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int t, n;
vector<ll> windows;
ll u, w, x;
map<ll, ll> mp;
ll topWindow = 0;
map<ll, ll> isTop;

//更新顶部窗口
void updateTop() {
    if (!windows.empty()) {
        if (isTop[topWindow] == false) {
            topWindow = windows[0];
        }
    }
    else {
        topWindow = 0;
    }
}
//打开窗口
void openWindow(string & msg) {
    cin >> u;
    if (mp.count(u) == 0) {//没找到u
        windows.push_back(u);
        mp[u] = 0;
        msg = "success";
    }
    else {
        msg = "same likeness";
    }
}
//关闭窗口
void closeWindow(string & msg) {
    cin >> u;
    if (mp.count(u) == 0) {
        msg = "invalid likeness";
    }
    else {
        msg = "close "  + to_string(u) + " with " + to_string(mp[u]);
        windows.erase(std::find(windows.begin(), windows.end(),u));
        mp.erase(u);
    }
}
//顶部窗口聊天
void Chat(string & msg) {
    cin >> w;
    if (windows.empty()) {
        msg = "empty";
    }
    else {
        mp[topWindow] += w;
        msg = "success";
    }
}
//选择第x个数置为队首
void Rotate(string & msg) {
    cin >> x;
    if (x > windows.size() || x < 1) {
        msg = "out of range";
    }
    else {
        ll tmp = windows[x - 1];
        windows.erase(std::find(windows.begin(), windows.end(),tmp));
        windows.insert(windows.begin(), tmp); // 先删除后插入
        msg = "success";
    }
}
//选择最大的u置为队首
void Prior(string & msg) {
    if (windows.empty()) {
        msg = "empty";
    }
    else {
        ll tmp = mp.rbegin()->first; //喜爱度最大的窗口
        windows.erase(std::find(windows.begin(), windows.end(),tmp));
        windows.insert(windows.begin(), tmp);
        msg = "success";
    }
}
//选择u置为队首
void Choose(string & msg) {
    cin >> u;
    if (mp.count(u) == 0) {
        msg = "invalid likeness";
    }
    else {
        windows.erase(std::find(windows.begin(), windows.end(),u));
        windows.insert(windows.begin(), u);
        msg = "success";
    }
}
//设为置顶
void Top(string & msg) {
    cin >> u;
    if (mp.count(u) == 0) {
        msg = "invalid likeness";
    }
    else {
        isTop[topWindow] = false; //将已有的置顶状态删除
        isTop[u] = true; //将u置为置顶
        topWindow = u;
        msg = "success";
    }
}
//取消置顶
void unTop(string & msg) {
    if (isTop[topWindow] == false) {
        msg = "no such person";
    }
    else {
        msg = "success";
        //解除已有的置顶状态
        isTop[topWindow] = false;
    }
}
int main() {
    cin >> t;
//    ofstream outfile("outputTest.txt", ios::trunc); // 输出到outputTest.txt文件
    while (t--) {
        //初始化容器
        windows.clear();
        mp.clear();
        topWindow = 0;
        isTop.clear();

        string msg;
        string op;
        cin >> n;
        int i;
        for (i = 1 ; i <= n ; i++) {
            cin >> op;
            if (op == "Add")  {
                openWindow(msg);
            }
            else if (op == "Close") {
                closeWindow(msg);
            }
            else if (op == "Chat") {
                Chat(msg);
            }
            else if (op == "Rotate") {
                Rotate(msg);
            }
            else if (op == "Prior") {
                Prior(msg);
            }
            else if (op == "Choose") {
                Choose(msg);
            }
            else if (op == "Top") {
                Top(msg);
            }
            else {
                unTop(msg);
            }

            updateTop();
            cout << "OpId #" << i << ": "<<msg <<"." << endl;
        }

        //清空队列, 有mp值则输出
        while (!windows.empty()) {
            if (mp[topWindow] != 0) {
                cout << "OpId #" << i++ << ": "<<"Bye "<< topWindow <<": " <<mp[topWindow] << "." <<endl;
            }
            windows.erase(std::find(windows.begin(), windows.end(),topWindow));
            mp.erase(topWindow);
            isTop[topWindow] = false; // 将置顶状态取消
            updateTop();
        }

    }
}