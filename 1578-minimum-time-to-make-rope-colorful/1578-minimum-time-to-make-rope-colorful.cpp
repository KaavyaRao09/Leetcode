class Solution {
public:
    long long minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        long long ans = 0;
        int prev_idx = 0;

        for (int i = 1; i < n; ++i) {
            if (colors[i] == colors[prev_idx]) {
                if (neededTime[i] < neededTime[prev_idx]) {
                    ans += neededTime[i];
                } else {
                    ans += neededTime[prev_idx];
                    prev_idx = i;
                }
            } else {
                prev_idx = i;
            }
        }
        return ans;
    }
};