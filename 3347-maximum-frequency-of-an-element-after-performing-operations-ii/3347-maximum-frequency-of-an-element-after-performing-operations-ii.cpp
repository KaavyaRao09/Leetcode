#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<long long, int> freq;
        map<long long, int> diff;

        // 1️⃣  mark contribution ranges and count originals
        for (long long num : nums) {
            freq[num]++;
            diff[num];                  // ensure key exists
            diff[num - k]++;            // start of reachable range
            diff[num + k + 1]--;        // end (exclusive)
        }

        // 2️⃣  sweep through sorted positions
        long long running = 0;
        int result = 0;
        for (auto &[pos, delta] : diff) {
            running += delta; // current total count of values reaching 'pos'
            int original = freq.count(pos) ? freq[pos] : 0;
            // we can at most use numOperations transformations plus originals
            result = max(result, (int)min(running, (long long)original + numOperations));
        }

        return result;
    }
};


