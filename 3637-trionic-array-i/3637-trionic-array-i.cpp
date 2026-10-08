class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool c1 = false; // increasing
        bool c2 = false; // decreasing
        bool c3 = false; // increasing again

        for (int i = 1; i < nums.size(); i++) {
            int prev = nums[i - 1];
            int curr = nums[i];

            // Phase 1: increasing
            if (!c1) {
                if (curr > prev) {
                    c1 = true; //condition 1 satisfied
                } else {
                    return false; // must increase in the start
                }
            }

            // Phase 2: decreasing
            else if (c1 && !c2) {
                if (curr > prev) {
                    continue;  // still increasing (consider in phase1)
                } else if (curr < prev) {
                    c2 = true; // decreasing started (condition 2 satisfied)
                } else {
                    return false; // no flat values allowed
                }
            }

            // Phase 3 start: increasing again
            else if (c1 && c2 && !c3) {
                if (curr < prev) {
                    continue; // still decreasing (consider in phase2)
                } else if (curr == prev) {
                    return false; // no flat values allowed
                } else {
                    c3 = true; // second increasing started (condition 3 satisfied)
                }
            }

            // Phase 3 continuation: must strictly increase
            else if (c1 && c2 && c3) {
                if (curr <= prev) {
                    return false; // cannot go down or stay flat
                }
            }
        }

        return c1 && c2 && c3;
    }
};