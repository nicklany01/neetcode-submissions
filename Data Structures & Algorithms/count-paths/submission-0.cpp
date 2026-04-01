class Solution {
public:
    int uniquePaths(int m, int n) {
        // f - we want the number of unique paths up until that point
        // a - rule is we can go down or right (i+1 or j+1)
        // s - dp[i][j] = dp[i-1][j] + dp[i][j-1]
        // t - we need to fill in outlines first, then we can fill it in
        //     from i = 0 to m, j = 1 to n or vise versa, doesnt matter
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
