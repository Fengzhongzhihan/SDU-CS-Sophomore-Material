//
// Created by Lenovo on 2024-06-12.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll n, seed, k;
ll res;
const int N = 1e7 + 10;
int s[N];
deque<int> maxq;
deque<int> minq;
uint32_t perturb(uint32_t value) {
    value ^= (value << 13);
    value ^= (value >> 17);
    value ^= (value << 5);
    return value;
}

std::vector<int> generate_sequence(uint32_t seed, int size) {
    seed = perturb(seed);
    std::vector<int> sequence;
    sequence.reserve(size);
    uint32_t state[4];
    state[0] = seed;
    state[1] = seed ^ 0xDEADBEEF;
    state[2] = seed ^ 0xCAFEBABE;
    state[3] = seed ^ 0xFACEFEED;

    auto xorshift128 = [&state]() -> uint32_t {
        uint32_t t = state[3];
        uint32_t const s = state[0];
        state[3] = state[2];
        state[2] = state[1];
        state[1] = s;
        t ^= t << 11;
        t ^= t >> 8;
        state[0] = t ^ s ^ (s >> 19);
        return state[0];
    };
    for (int i = 0; i < size; ++i) {
        sequence.push_back(int(xorshift128() % size));
    }
    return sequence;
}

void solve(vector<int>v) {
    int r = 0;
    for (int l = 0 ; l < n ; l++ ) {
        while (r < n) {
            while (maxq.size() && v[r] > maxq.back()){
                maxq.pop_back();
            }
            while (minq.size() && v[r] < minq.back()) {
                minq.pop_back();
            }
            maxq.push_back(v[r]);
            minq.push_back(v[r]);
            if (maxq.front() - minq.front() > k)  {
                break;
            }else {
                r++;
                res += minq.front();
            }
        }
        if (maxq.front() == v[l]) {
            maxq.pop_front();
        }
        if (minq.front() == v[l]) {
            minq.pop_front();
        }
    }
}

signed main() {
    cin >> n >> seed >> k;
    vector<int> v = generate_sequence(seed, n);
    for (int i = 1 ; i <= n; i++) {
        s[i] = s[i - 1] + v[i - 1];
    }
    solve(v);
    cout << res <<endl;
}