class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> lower(26, -1);

        vector<int> upper(26, -1);

        for (int i = 0; i < word.size(); i++) {

            char ch = word[i];

            if (ch >= 'a' && ch <= 'z') {

                lower[ch - 'a'] = i;
            }
            else {

                int idx = ch - 'A';

                if (upper[idx] == -1) {
                    upper[idx] = i;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {

            if (lower[i] != -1 && upper[i] != -1) {

                if (lower[i] < upper[i]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};