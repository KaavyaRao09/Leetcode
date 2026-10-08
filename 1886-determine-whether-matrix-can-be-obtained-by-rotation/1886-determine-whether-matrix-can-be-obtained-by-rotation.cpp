class Solution {
public:
    bool findRotation(vector<vector<int>>& m, vector<vector<int>>& t) {
        int n = m.size();
        bool r0 = true, r1 = true, r2 = true, r3 = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (m[i][j] != t[i][j]) r0 = false;
                if (m[n - 1 - j][i] != t[i][j]) r1 = false;
                if (m[n - 1 - i][n - 1 - j] != t[i][j]) r2 = false;
                if (m[j][n - 1 - i] != t[i][j]) r3 = false;
            }
        }
        return r0 || r1 || r2 || r3;
    }
};