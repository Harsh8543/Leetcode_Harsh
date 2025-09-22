class Solution {
    int Number(int index, int amount, int n, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 0; 
        if (index == n || amount < 0) return 1e9;

        if (dp[index][amount] != -1) {
            return dp[index][amount];
        }

        int take = 1 + Number(index, amount - coins[index], n, coins, dp);
        int skip = Number(index + 1, amount, n, coins, dp);

        return dp[index][amount] = min(take, skip);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = Number(0, amount, n, coins, dp);
        if (ans >= 1e9) return -1;  
        return ans;
    }
};
