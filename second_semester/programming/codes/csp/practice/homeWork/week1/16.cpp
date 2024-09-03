#include<iostream>
using namespace std;
int a, b;
int main ()
{
    while (scanf("%x%x", &a, &b) != EOF) {
        printf("%d\n", a + b);
    }    

    return 0;
}