class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // s - value is number of ways/permutations. track nums index, and current sum
        // d - choice is to add or subtract a number. dp[i][j] depends on dp[i-1][j+nums[i]] and dp[i-1][j-nums[i]]
        // f - dp[i][j] += dp[i-1][j+nums[i]] + dp[i-1][j-nums[i]]
        // o - cant linear. initialise dp[0][0]
        int n = nums.size() + 1; // pad so we dont need to initialise first row seperately
        // get how big our table needs to be
        int offset = 0;
        for (auto num : nums) {
            offset += num;
        }
        int m = offset * 2 + 1;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[1][offset + nums[0]] += 1; // excess representation of negatives
        dp[1][offset - nums[0]] += 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // subtract number
                if (j + nums[i-1] < m) {
                    dp[i][j] += dp[i-1][j+nums[i-1]];
                }
                // add number
                if (j - nums[i-1] >= 0) {
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }
                cout << "i: " << i << ", j: " << j-offset << ", dp: " << dp[i][j] << endl;
            }
        }
        return dp[n-1][target+offset];
    }
};
