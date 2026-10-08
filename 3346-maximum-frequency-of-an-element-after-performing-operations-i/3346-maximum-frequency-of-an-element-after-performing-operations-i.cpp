#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        if (nums.empty()) return 0;
        // count of original numbers
        unordered_map<long long,int> cnt;
        // difference map for sweep line: +1 at (num - k), -1 at (num + k + 1)
        map<long long,int> diff;
        // candidate positions to check (sorted)
        set<long long> candidates;

        for (long long x : nums) {
            ++cnt[x];
            diff[x - k] += 1;
            diff[x + k + 1] -= 1;
            candidates.insert(x - k);
            candidates.insert(x);
            candidates.insert(x + k + 1);
        }

        int ans = 1;
        long long adjustable = 0; // running sum from difference map

        for (long long pos : candidates) {
            // update adjustable by diff at this pos (if any)
            auto it = diff.find(pos);
            if (it != diff.end()) adjustable += it->second;

            int countAtPos = 0;
            auto itc = cnt.find(pos);
            if (itc != cnt.end()) countAtPos = itc->second;

            long long canAdjust = adjustable - countAtPos; // elements reach pos but not already equal
            if (canAdjust < 0) canAdjust = 0;

            long long add = min<long long>(numOperations, canAdjust);
            ans = max(ans, countAtPos + (int)add);
        }

        return ans;
    }
};