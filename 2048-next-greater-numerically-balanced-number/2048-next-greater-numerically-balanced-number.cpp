class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; ; ++i) {
            if (isBeautiful(i)) return i;
        }
    }

private:
    bool isBeautiful(int num) {
        vector<int> count(10, 0);
        while (num) {
            count[num % 10]++;
            num /= 10;
        }
        for (int d = 0; d <= 9; ++d) {
            if (count[d] && count[d] != d) return false;
        }
        return true;
    }
};