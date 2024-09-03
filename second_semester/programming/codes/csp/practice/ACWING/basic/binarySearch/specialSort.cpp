//
// Created by Lenovo on 2024-06-04.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> res(1, 1);
        for (int i = 2; i <= N; i++) {
            int l = 0, r = res.size() - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (compare(res[mid], i)) { // i > res[mid]
                    l = mid;
                }else {
                    r = mid - 1;
                }
            }
            res.push_back(i);
            for (int j = res.size() - 2; j > r ; j--) {
                swap(res[j], res[j + 1]);
            }
            if (compare(res[r], i)) { // 如果r < i
                swap(res[r], res[r + 1]);
            }
        }
    }
};