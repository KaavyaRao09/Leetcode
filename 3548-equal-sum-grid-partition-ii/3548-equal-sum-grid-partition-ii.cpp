class Solution {
public:
    typedef long long ll;

    bool check(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        vector<int> freqTop(100001, 0), freqBottom(100001, 0);

        ll total = 0;
        for (auto &row : g) {
            for (int val : row) {
                total += val;
                freqBottom[val]++;
            }
        }

        ll topSum = 0, bottomSum = total;

        for (int i = 0; i < n - 1; i++) {

            for (int j = 0; j < m; j++) {
                int val = g[i][j];
                topSum += val;
                bottomSum -= val;
                freqTop[val]++;
                freqBottom[val]--;
            }

            if (topSum == bottomSum) return true;

            if (topSum > bottomSum) {
                ll diff = topSum - bottomSum;

                if (diff <= 100000 && canRemove(g, freqTop, diff, i + 1, m, true))
                    return true;
            }

            else {
                ll diff = bottomSum - topSum;

                if (diff <= 100000 && canRemove(g, freqBottom, diff, n - i - 1, m, false))
                    return true;
            }
        }

        return false;
    }

    bool canRemove(vector<vector<int>>& g, vector<int>& freq,
                   ll diff, int h, int w, bool isTop) {

        if (h > 1 && w > 1) {
            return freq[diff] > 0;
        }

        if (w == 1) {
            if (isTop) {
                return g[0][0] == diff || g[h - 1][0] == diff;
            } else {
                int n = g.size();
                return g[n - h][0] == diff || g[n - 1][0] == diff;
            }
        }

        if (h == 1) {
            if (isTop) {
                return g[0][0] == diff || g[0][w - 1] == diff;
            } else {
                int n = g.size();
                return g[n - 1][0] == diff || g[n - 1][w - 1] == diff;
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {

        if (check(grid)) return true;

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> t(m, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                t[j][i] = grid[i][j];

        return check(t);
    }
};