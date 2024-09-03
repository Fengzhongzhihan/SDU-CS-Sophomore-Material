//
// Created by Lenovo on 2024-04-24.
//
#include "bits/stdc++.h"
using  namespace std;
typedef long long ll;

struct FileNode{
    map <string , FileNode> children; // 孩子, 通过文件名 -> FileNode
    ll LD, LR;  // 规定 LD : 孩子配额 LR: 后代配额
    ll SD, SR;  // 实际 SD : 孩子 SR : 后代
    ll fileSize; // 文件大小
    bool isDir; // 判断是否是一个目录

    FileNode() { // 初始化
        LD = LR = 1e18;
        SD = SR = fileSize = 0;
        isDir = true;
    }
}root; // 定义了根节点

vector<string> nameList; //
vector<FileNode*> nodeList; //

void updPath() {
    nameList.clear();
    nodeList.clear();
    string path;
    cin >> path; // 读入一个路径
    // 分割
    string cur;
    stringstream ss(path);
    while (getline(ss, cur, '/')) // 按照斜杠分隔开
    {
        nameList.push_back(cur);
    }

    FileNode *f = &root;
    nodeList.push_back(f); // 放入根节点
    //从第一个名字开始遍历, 因为第一个总是""
    for (int i = 1; i < nameList.size(); i++) {
        string & cur_name = nameList[i];//   /A/B/C/F  /A/B/C/D
        if (!f->isDir || f->children.count(cur_name) == 0) {
            break; // f是普通文件 / f没有该孩子 , 则不把f加入nodelist中
        }
        f = &f->children[cur_name];
        nodeList.push_back(f);
    }
}
void change_quota(ll inc, bool isFile = true) {
    //修改配额
    for (int i = 0 ; i < nodeList.size(); i++) {
        nodeList[i]->SR += inc;
        if (i == nameList.size() - 2 && isFile) { // 如果是文件才需要进行SD的更新
            nodeList[i]->SD += inc;
        }
    }
}

bool create() {
    ll fileSize ;
    cin >> fileSize;
    ll inc = fileSize;
    auto lastNode = nodeList.back();
    //如果找到了这个文件  对应已有 /A/B/C/D  查找/A/B/C
    if (nameList.size() == nodeList.size()) {
        if (lastNode->isDir) { // 如果是一个目录, 则不创建, 返回错误
            return false;
        }

        inc = fileSize - lastNode->fileSize; // 如果是普通文件, 则进行替换, 此时差值为提供的size - 原有的size
    }
    //没找到文件 且 最后一个是普通文件, 则返回错误 对应已有 /A/B/C/D  查找/A/D
    else {
        if (!lastNode->isDir) {
            return false;
        }
    }

    //考虑是否要新建目录
    for (int i = 0 ; i < nodeList.size(); i++) {
        // 改变所有结点的后代校验
        if (nodeList[i]->SR + inc > nodeList[i] ->LR) {
            return false;
        }
        // 只改变父亲结点的孩子校验
        if (i == nameList.size() - 2) {
            if (nodeList[i]->SD + inc > nodeList[i] -> LD) {
                return false;
            }
        }
    }
    //更新目录   /A/B/C/D  /A/B/E/F
    for (int i = (int)nodeList.size(); i < nameList.size(); i++) {
       // nodeList.back()->children[nameList[i]] 创建了一个map[namelist[i]]
        nodeList.push_back(&nodeList.back()->children[nameList[i]]);
    }

    //改变配额
    change_quota(inc, true);

    //更新内容
    nodeList.back()->fileSize = fileSize;
    nodeList.back()->isDir = false;

    return true;
}

//移除文件
bool remove() {
    //没找到这个文件
    if (nameList.size() != nodeList.size()) {
        return true;
    }

    auto lastNode = nodeList.back();
    if (lastNode->isDir) { // 是目录, 移除配额值
        change_quota(-lastNode->SR, false);
    }
    else { //不是目录, 移除文件大小
        change_quota(-lastNode->fileSize);
    }

    nodeList[nodeList.size() - 2] ->children.erase(nameList.back());
    return true;
}
//设定配额
bool quota() {
    ll LD, LR;
    cin >> LD >> LR;
    if (LD == 0) {
        LD = 1e18;
    }
    if (LR == 0) {
        LR = 1e18;
    }

    //没找到文件
    if (nameList.size() != nodeList.size()) {
        return false;
    }
    auto lastNode = nodeList.back();
    if (!lastNode->isDir) {//是普通文件
        return false;
    }

    if (lastNode->SD > LD || lastNode->SR > LR) { // 无法承担
        return false;
    }

    lastNode->LD = LD;
    lastNode->LR = LR;
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        updPath();
        bool is_success = false;
        if (op == "C") {
            is_success = create();
        } else if (op == "R") {
            is_success = remove();
        } else {
            is_success = quota();
        }
        if (is_success) cout << "Y\n";
        else {
            cout << "N\n";
        }
    }

    return 0;
}