class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n);
        long long curLen = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                curLen++;
            } else if (c == '*') {
                if (curLen > 0) curLen--;
            } else if (c == '#') {
                curLen *= 2;
            } else {
            }

            len[i] = curLen;
        }

        if (k >= curLen) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            long long after = len[i];
            long long before = (i == 0 ? 0 : len[i - 1]);

            if (c >= 'a' && c <= 'z') {
                if (k == before) return c;
            } else if (c == '#') {
                if (before > 0) k %= before;
            } else if (c == '%') {
                k = before - 1 - k;
            } else {
            }
        }

        return '.';
    }
};