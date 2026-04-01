class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // state - the number of common chars up to that point. i will index text1, j will index text2.
        // dependencies - choice is if char i and j match, then we add 1 to the previous running count.
        // if they dont match, dp[i][j] relies on dp[i-1][j] and dp[i][j-1] because we advance one of the chars
        // if they do match, we advance both the chars, and use dp[i-1][j-1]
        // formula - dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1
        // order - linear from either i or j
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for (int i = 1; i < text1.size()+1; i++) {
            for (int j = 1; j < text2.size()+1; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
