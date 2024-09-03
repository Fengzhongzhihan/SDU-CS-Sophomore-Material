    //
    // Created by Lenovo on 2024-03-29.
    //
    #include "bits/stdc++.h"
    using namespace std;
    struct message {
        string version, sourceIP, desIP, stateCode, stateNum, len, data;
    };//定义报文信息
    vector<message> v;  //存储message
    map<string, string> IP2name; // 将IP -> name
    map<string, string> name2IP; // 将name -> IP
    int n;
    const char * ver_23 = "Ver23*"; // 23版
    const char * catCat =  "022222222222"; // 猫猫服务器地址
    const char * broadCast = "099999999999"; // 广播服务器地址

    void chat(message m) { // 处理聊天信息
        //没有相关的注册信息了, 则返回
        if (IP2name.count(m.sourceIP) == 0) {
            return;
        }
        string userName = IP2name[m.sourceIP];
        string resLen = ""; // 此时的len字符串会改变, 不能直接使用m.len
        int l = 1; //包含冒号
        for (int i = 0 ; i < 4 ; i++ ){
            l += (m.len[i] - '0') * pow (10, 3 - i);
        }
        l += userName.size(); // 先转化为int类型
        //将整数转化为四位字符串
        for (int i = 3 ; i >= 0 ; i--) {
            char c = l / pow (10, i) + '0';
            l = l % int (pow(10, i));
            resLen += c;
        }
        cout << m.version << catCat <<broadCast<< "0" << "99" << resLen << userName << ":" << m.data ; //输出广播信息
    }

    void reg(message m) {
        // 已经有相关的注册信息了, 则返回
        if (IP2name.count(m.sourceIP) != 0 ) {
            return;
        }
        string userName = m.data;
        if (name2IP.count(userName) != 0) { //用户名已经被使用
            return;
        }
        //判断用户名是否合法
        if (userName.size() < 1) return;
        for (int i =0 ; i < userName.size(); i++ ) {
            if (userName[i] < 'a' || userName[i] > 'z') {
                return;
            }
        }
        //地址与用户名绑定, 注意需要双向存储
        IP2name[m.sourceIP] = m.data;
        name2IP[m.data] = m.sourceIP;
        cout << m.version << catCat <<m.sourceIP<< "1" << "01" << m.len << m.data ;

    }

    void del (message m) {
        //没有注册过,拒绝
        if (IP2name.count(m.sourceIP) == 0) {
            return;
        }
        string userName = IP2name[m.sourceIP];
        //发过来的地址对应的用户名 和 发过来的用户名不匹配
        if (userName != m.data) {
            return;
        }
        cout << m.version << catCat <<m.sourceIP<< "1" << "03" << m.len << m.data ;
        // 注意两个map均需要删除
        IP2name.erase(m.sourceIP);
        name2IP.erase(userName);
    }

    int main() {
        cin >> n;
        getchar() ; // 读取回车
        // n个报文
        for (int j = 0; j  < n ; j++) {
            char c;
            string version = "", sourceIP = "", desIP = "", stateCode = "", stateNum = "", data = "", len ="";
            //读入版本号
            while (scanf("%c", &c)) {
                version += c;
                if (c == '*') {
                    break;
                }
            }
            //读入源地址
            int cnt = 0;
            while (scanf("%c", &c)) {
                sourceIP += c;
                cnt ++;
                if (cnt == 12) {
                    break;
                }
            }
            //读入目的地地址
            cnt = 0;
            while (scanf("%c", &c)) {
                desIP += c;
                cnt ++;
                if (cnt == 12) {
                    break;
                }
            }
            //读入状态码
            scanf("%c", &c); stateCode = c;
            // 读入状态号
            for (int i = 0 ; i < 2; i++) {
                scanf("%c", &c); stateNum += c;
            }
            //读入数据长度
            cnt = 0;
            while (scanf("%c", &c)) {
                len += c;
                cnt ++;
                if (cnt == 4) {
                    break;
                }
            }
            //读出len的值
            int l = 0;
            for (int i =0 ; i  < 4 ; i++) {
                l += (len[i] - '0') * pow (10, 3 - i);
            }
            //读入数据
            for (int i = 0 ; i < l ; i++) {
                scanf("%c", &c);
                data += c;
            }
            v.push_back({version, sourceIP, desIP, stateCode, stateNum,len, data});
        }

        for (int i = 0; i < v.size(); i++) {
            auto t = v[i];
            // 如果版本号不对 or 源地址和目的地址 均为猫猫 or 目的地址不为猫猫 均拒绝
            if (t.version != ver_23 || t.desIP != catCat || t.sourceIP == catCat || t.sourceIP == broadCast) {
                continue;
            }
            //注册报文
            if (t.stateCode == "1" && t.stateNum == "00") {
                reg(t);
            }
            //注销报文
            else if (t.stateCode == "1" && t.stateNum == "02") {
                del(t);
            }
            //聊天报文
            else if (t.stateCode == "0" && t.stateNum == "08") {
                chat(t);
            }
        }
    }
