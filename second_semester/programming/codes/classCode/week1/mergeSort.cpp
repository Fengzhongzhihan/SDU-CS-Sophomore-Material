#include<iostream>
using namespace std;
int n;
const int N=10;
int tmp[N], q[N];

void mergeSort(int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = l + r >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    int k = 0;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            tmp[k++] = q[i++];
        }
        else {
            tmp[k++] = q[j++];
        }
    }

    while(i <= mid) {
        tmp[k++] = q[i++];
    }

    while (j <= r ) {
        tmp[k++] = q[j++];
    }

    for (int i = l, j = 0; i <= r ;i++, j++) {
        q[i] = tmp[j];
    }
}

int main() {

    freopen("a.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n ;i++) {
        cin >> q[i];
    }

    mergeSort(0, n-1);

    for (int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    return 0;
}

//scanf("%s", s); scanf("%s%s", s+1, s+2)