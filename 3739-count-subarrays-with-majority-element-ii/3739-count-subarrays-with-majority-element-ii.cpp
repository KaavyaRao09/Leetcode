class Solution {
public:
    class Fenwick {
    public:
        vector<int> bit;

        Fenwick(int n) {
            bit.assign(n + 1, 0);
        }

        void update(int idx) {
            while (idx < bit.size()) {
                bit[idx]++;
                idx += idx & -idx;
            }
        }

        long long query(int idx) {
            long long sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> values = pref;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        Fenwick ft(values.size());

        long long ans = 0;

        for (int x : pref) {

            int idx = lower_bound(values.begin(), values.end(), x) - values.begin() + 1;

            ans += ft.query(idx - 1);

            ft.update(idx);
        }

        return ans;
    }
};