class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        vector<int> group(n, -1);

        int curGroup = 0;

        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                if (curGroup == 26) return "";
                group[i] = curGroup++;

                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        group[j] = group[i];
                    }
                }
            }
        }

        string ans(n, 'a');
        for (int i = 0; i < n; i++) {
            ans[i] = 'a' + group[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (ans[i] == ans[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }

        return ans;
    }
};