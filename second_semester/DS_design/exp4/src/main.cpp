#include "graph.h"
int main() {
//    int n, m, d;
//    cin >> n >> m >> d;
//    Graph g(n, m, d);
//    for (int i = 0 ; i < m ; i++) {
//        int a, b , c;
//        cin >> a >> b >> c;
//        g.add(a, b, c);
//    }
    Graph g;
    bool flag = true;
    for (int i = 1; i <= 100; i++) {
        g.init();
        g.readFile("input" + to_string(i) + ".in");
        g.solve1(i);
        if (g.compareFile(to_string(i) + ".out") == false) {
            flag = false;
            break;
        }
        g.init();
        g.readFile("input" + to_string(i) + ".in");
        g.solve2(i);
        if (g.compareFile(to_string(i) + ".out") == false) {
            flag = false;
            break;
        }
    }
    if (flag == true) {
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }
    return 0;
}
