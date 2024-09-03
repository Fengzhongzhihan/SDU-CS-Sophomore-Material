#include<iostream>
#include<math.h>
#define pi  3.14159265358979323846264338;
using namespace std;
double a, b, H, M;
int main ()
{
    cin >> a >> b >> H >> M;
    double xith = (H + M / 60 ) / 12 * 2 * pi;
    double xitm = M / 60 * 2 * pi;
    double hx = cos(xith) * a;
    double hy = sin(xith) * a;
    double mx = cos(xitm) * b;
    double my = sin(xitm) * b;

    //计算长度
    double res = sqrt(pow(hx - mx, 2) + pow(hy - my, 2));

    printf("%.20f", res);
}