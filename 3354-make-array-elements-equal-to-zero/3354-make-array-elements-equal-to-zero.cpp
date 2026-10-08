#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        int leftSum = 0; // sum of elements strictly to the left of current index

        for (int i = 0; i < n; ++i) {
            // only starting positions with nums[i] == 0 are allowed
            if (nums[i] == 0) {
                int rightSum = total - leftSum; // since nums[i] == 0, suffix = total - leftSum
                if (leftSum == rightSum) ans += 2;           // can go either left or right
                else if (abs(leftSum - rightSum) == 1) ans += 1; // can go only to the larger side
            }
            leftSum += nums[i]; // move prefix window forward
        }
        return ans;
    }
};