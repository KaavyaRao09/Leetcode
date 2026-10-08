class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int top[3] = {0, 0, 0};
        auto add = [&](int val) {
            if (val == top[0] || val == top[1] || val == top[2]) return;
            if (val > top[0]) {
                top[2] = top[1];
                top[1] = top[0];
                top[0] = val;
            } else if (val > top[1]) {
                top[2] = top[1];
                top[1] = val;
            } else if (val > top[2]) {
                top[2] = val;
            }
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                add(grid[i][j]);
                int maxK = min({i, m - 1 - i, j, n - 1 - j});
                for (int k = 1; k <= maxK; ++k) {
                    int current_sum = 0;
                    for (int step = 0; step < k; ++step) {
                        current_sum += grid[i - k + step][j + step];
                        current_sum += grid[i + step][j + k - step];
                        current_sum += grid[i + k - step][j - step];
                        current_sum += grid[i - step][j - k + step];
                    }
                    
                    add(current_sum);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < 3; ++i) {
            if (top[i] > 0) {
                ans.push_back(top[i]);
            }
        }
        return ans;
    }
};