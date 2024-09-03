#include<bits/stdc++.h>
using namespace std;

class Complex {
    public :
        Complex (double realNumber, int comNumber) {
            real_number = realNumber;
            com_number = comNumber;
        }

        Complex (double realNumber) {
            real_number = realNumber;
        }

        Complex () {
            real_number = 0;
            com_number = 0;
        }

        void add (const Complex & x) {
            this->com_number += x.com_number;
            this->real_number += x.real_number;
        }

        void show () {
            cout << real_number;
            if (com_number != 0) {
                cout << "+" << com_number <<"i" << endl; 
            }
        }
    private :
        double real_number = 0;
        int com_number = 0;
};


int main() {
    Complex c1(3, 5);
    Complex c2 = 3.5;
    c1.add(c2);
    c1.show();
}