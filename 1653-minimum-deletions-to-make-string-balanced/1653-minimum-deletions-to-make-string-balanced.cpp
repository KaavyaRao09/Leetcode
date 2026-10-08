class Solution {
public:
    int minimumDeletions(string s) {
        int countB = 0;
        int deletions = 0;

        for (char ch : s) {
            if (ch == 'b') {
                countB++;
            } else {
                deletions = min(deletions + 1, countB);
            }
        }
        return deletions;
    }
};