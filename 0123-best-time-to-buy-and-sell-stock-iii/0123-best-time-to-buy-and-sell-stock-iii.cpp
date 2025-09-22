class Solution {
public:
    int n;
    int dp[100001][2][3]; // dp[index][buy][cap]

    int f(int ind, int buy, int cap, vector<int>& prices) {
        // base cases
        if (cap == 0) return 0;
        if (ind == n) return 0;

        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        if (buy) {
            // option 1: buy now -> -prices[ind] + f(ind+1, 0, cap)
            // option 2: skip -> f(ind+1, 1, cap)
            return dp[ind][buy][cap] = max(
                -prices[ind] + f(ind + 1, 0, cap, prices),
                0 + f(ind + 1, 1, cap, prices)
            );
        } else {
            // option 1: sell now -> prices[ind] + f(ind+1, 1, cap-1)
            // option 2: skip -> f(ind+1, 0, cap)
            return dp[ind][buy][cap] = max(
                prices[ind] + f(ind + 1, 1, cap - 1, prices),
                0 + f(ind + 1, 0, cap, prices)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return f(0, 1, 2, prices); // start at day 0, we can buy, 2 transactions allowed
    }
};
