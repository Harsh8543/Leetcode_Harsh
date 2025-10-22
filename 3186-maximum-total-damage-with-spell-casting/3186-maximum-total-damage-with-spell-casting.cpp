class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<long long, long long> damageMap;
        for (int val : power) damageMap[val] += val;

        vector<pair<long long, long long>> arr;
        for (auto &it : damageMap) arr.push_back(it);

        int n = arr.size();
        vector<long long> dp(n, 0);

        dp[0] = arr[0].second;

        for (int i = 1; i < n; i++) {
            long long take = arr[i].second;
            int j = i - 1;
            while (j >= 0 && arr[i].first - arr[j].first <= 2) j--;
            if (j >= 0) take += dp[j];

            dp[i] = max(dp[i - 1], take);
        }

        return dp[n - 1];
    }
};