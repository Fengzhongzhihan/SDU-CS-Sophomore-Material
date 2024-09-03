#include<bits/stdc++.h>
using namespace std;

class Tree {
    public : 
        Tree (int n = 0) {
            ages = n;
        }
        void grow (int years) {
            ages += years;
        }

        void age() {
            cout << "这棵树的年龄为" << ages << endl;
        }

    private : 
        int ages;

};

