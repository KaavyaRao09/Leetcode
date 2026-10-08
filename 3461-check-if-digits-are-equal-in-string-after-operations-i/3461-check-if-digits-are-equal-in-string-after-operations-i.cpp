class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            string nxt = "";
            for (int i = 0; i < s.length() - 1; ++i) {
                int sm = (s[i] - '0' + s[i + 1] - '0') % 10;
                nxt += to_string(sm);
            }
            s = nxt;
        }
        return s[0] == s[1];
    }
};