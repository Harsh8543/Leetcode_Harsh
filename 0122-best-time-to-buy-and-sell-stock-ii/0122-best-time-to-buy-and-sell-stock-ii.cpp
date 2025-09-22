class Solution {
    int maxProfitRec(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (ind == prices.size()) return 0;

        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;

        if (buy) {
            // Choice: buy or skip
            int take = -prices[ind] + maxProfitRec(ind + 1, 0, prices, dp);
            int notTake = 0 + maxProfitRec(ind + 1, 1, prices, dp);
            profit = max(take, notTake);
        } else {
            // Choice: sell or skip
            int sell = prices[ind] + maxProfitRec(ind + 1, 1, prices, dp);
            int notSell = 0 + maxProfitRec(ind + 1, 0, prices, dp);
            profit = max(sell, notSell);
        }

        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return maxProfitRec(0, 1, prices, dp); // start with buy = 1
    }
};
