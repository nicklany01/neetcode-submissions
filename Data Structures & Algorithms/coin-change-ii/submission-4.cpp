class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // s - value is number of combinations, keep track of amount left until target, which coin im on
        // d - choices are to use the same coin, or go to next coin. dp[i][j] depends on dp[i-1][j] and dp[i][j-coins[i]]
        // f - dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]]
        // o - linear across i, then j, although it doesnt matter. at end we should get dp[coins.size()][0]
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= coins.size(); i++) {
            for (int j = 0; j <= amount; j++) {
                // go to next coin
                dp[i][j] += dp[i-1][j];
                // use same coin again
                if (j >= coins[i-1]) {
                    dp[i][j] += dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};
