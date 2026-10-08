class Solution {
public:
    string result = "";
    int count = 0;

    void dfs(int n, int k, string &curr) {
        if (!result.empty()) return;

        if (curr.size() == n) {
            count++;
            if (count == k) result = curr;
            return;
        }

        for (char c : {'a','b','c'}) {
            if (!curr.empty() && curr.back() == c) continue;

            curr.push_back(c);
            dfs(n, k, curr);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        dfs(n, k, curr);
        return result;
    }
};