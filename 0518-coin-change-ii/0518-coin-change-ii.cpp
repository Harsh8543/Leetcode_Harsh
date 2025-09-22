class Solution {
    int Number(int index, int amount, int n, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 1; 
        if (index == n || amount < 0) return 0;

        if (dp[index][amount] != -1) return dp[index][amount];
        int take = Number(index, amount - coins[index], n, coins, dp);
        int skip = Number(index + 1, amount, n, coins, dp);

        return dp[index][amount] = take + skip;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return Number(0, amount, n, coins, dp);
    }
};
