class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        vector<int> count(n, 0);
        vector<int> result;
        for (int val : nums) {
            count[val]++;
        }
        for (int i = 0; i < n; ++i) {
            if (count[i] == 2) {
                result.push_back(i);
            }
        }
        return result;
    }
};
