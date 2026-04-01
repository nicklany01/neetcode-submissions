class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // s - state: max profit, state (i.e. have neetcoin, dont have neetcoin, dont have neetcoin and on cooldown)
        // d - max profit depends on previous max profit + price, depending on state
        // f - dp[0][i] = max(dp[0][i-1]+price[i], dp[2][i-1]+price[i]) // buy or keep the coin
        //     dp[1][i] = dp[0][i-1]
        //     dp[2][i] = dp[0][i-2]
        // o - linear
        vector<vector<int>> dp(3, vector<int>(prices.size()+1,0));
        dp[0][0] = -prices[0];
        for (int i = 1; i <= prices.size(); i++) {
            // owning state will be if we kept the previous owning state, or bought it from the non cooldown state
            dp[0][i] = max(dp[0][i-1], dp[2][i-1] - prices[i-1]);
            // we sold it
            dp[1][i] = dp[0][i-1] + prices[i-1];
            dp[2][i] = max(dp[1][i-1], dp[2][i-1]);
        }
        return max(dp[1][prices.size()], dp[2][prices.size()]);
    }
};
