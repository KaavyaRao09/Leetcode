class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        long long prev = 0;
        long long ans = 0;
        for (const string &row : bank) {
            long long cnt = 0;
            for (char c : row) if (c == '1') ++cnt;
            if (cnt > 0) {
                ans += prev * cnt;
                prev = cnt;
            }
        }
        return static_cast<int>(ans);
    }
};