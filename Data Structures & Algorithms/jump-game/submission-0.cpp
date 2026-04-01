class Solution {
public:
    bool canJump(vector<int>& nums) {
        // s - value: max value it can jump ahead, index: index of nums
        // d - choice is to jump forward one and updates the value it can jump forward by, only depends on previous
        // f - dp[i] = max(d[i-1] - 1, nums[i]) // this is how far forward it can reach now, assuming it was reachable
        // o - linear
        int n = nums.size() + 1;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (dp[i-1] > 0) { // could it reach this in the first place
                dp[i] = max(dp[i-1] - 1, nums[i-1]);
            } else {
                return false;
            }
        }
        return dp[n-2];
    }
};
