
class Solution {
    int robbery(int index, vector<int>& nums,vector<int>&dp) {
        if (index < 0) return 0;
        if (index == 0) return nums[0];
        if (index == 1) return max(nums[0], nums[1]);
      if(dp[index]!= -1){
        return dp[index];
      }
        return dp[index]=max(nums[index] + robbery(index - 2, nums,dp),robbery(index - 1, nums,dp));
    }
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int index = nums.size() - 1;
         vector<int> dp(nums.size(), -1);
        return robbery(index, nums,dp);
    }
};

