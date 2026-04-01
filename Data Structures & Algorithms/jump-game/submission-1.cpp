class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxJump = 1;
        for (int i = 0; i < n - 1; i++) {
            if (maxJump > 0) { // could it reach this in the first place
                maxJump = max(maxJump - 1, nums[i]);
            } else {
                return false;
            }
        }
        return maxJump;
    }
};
