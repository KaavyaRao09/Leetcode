#include <bits/stdc++.h>
using namespace std;

struct PairHash {
    size_t operator()(const pair<int,int>&p) const noexcept {
        return ((uint64_t)(p.first) << 32) ^ (uint32_t)(p.second);
    }
};

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int a = 0, b = 0, c = 0;
        int ans = 0;
        int run = 0;
        char prev = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || s[i] != prev) run = 1;
            else run++;
            prev = s[i];
            ans = max(ans, run);
        }

        unordered_map<pair<int,int>, int, PairHash> map3;
        unordered_map<pair<int,int>, int, PairHash> map_ab_c;
        unordered_map<pair<int,int>, int, PairHash> map_ac_b;
        unordered_map<pair<int,int>, int, PairHash> map_bc_a;

        map3[{0,0}] = 0;
        map_ab_c[{0,0}] = 0;
        map_ac_b[{0,0}] = 0;
        map_bc_a[{0,0}] = 0;

        for (int p = 1; p <= n; ++p) {
            char ch = s[p-1];
            if (ch == 'a') ++a;
            else if (ch == 'b') ++b;
            else ++c;

            pair<int,int> key3 = {b - a, c - a};
            if (map3.find(key3) != map3.end()) {
                ans = max(ans, p - map3[key3]);
            } else {
                map3[key3] = p;
            }

            pair<int,int> key_ab_c = {b - a, c};
            if (map_ab_c.find(key_ab_c) != map_ab_c.end()) {
                ans = max(ans, p - map_ab_c[key_ab_c]);
            } else {
                map_ab_c[key_ab_c] = p;
            }

            pair<int,int> key_ac_b = {c - a, b};
            if (map_ac_b.find(key_ac_b) != map_ac_b.end()) {
                ans = max(ans, p - map_ac_b[key_ac_b]);
            } else {
                map_ac_b[key_ac_b] = p;
            }

            pair<int,int> key_bc_a = {c - b, a};
            if (map_bc_a.find(key_bc_a) != map_bc_a.end()) {
                ans = max(ans, p - map_bc_a[key_bc_a]);
            } else {
                map_bc_a[key_bc_a] = p;
            }
        }

        return ans;
    }
};