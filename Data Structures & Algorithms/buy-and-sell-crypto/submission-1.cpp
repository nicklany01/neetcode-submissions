class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = prices[0];
        int maxProfit = 0;
        for (int p : prices) {
            minP = min(minP, p);
            maxProfit = max(maxProfit, p - minP);
        }
        return maxProfit;
    }
};
