#include "headQuarter.h"
int main() {
    int t, m;
    int d, n, i, l, w;
    cin >> t;
    for (int j = 1 ; j <= t ;j ++){
        cout << "Case:" << j << endl;
        cin >> m;
        cin >> d >> n >> i >> l >> w;
        //dragon、ninja、iceman、lion、wolf 1 2 3 4 5
        headQuarter redHeadQuarter(0, m, new int[6]{0, 3, 4, 5, 2, 1},
                                   new int[6]{0, d, n, i, l, w});
        headQuarter blueHeadQuarter(1, m, new int[6]{0, 4, 1, 2, 3, 5},
                                    new int[6]{0, d, n, i, l, w});
        makeWarriors(redHeadQuarter, blueHeadQuarter);
    }
}