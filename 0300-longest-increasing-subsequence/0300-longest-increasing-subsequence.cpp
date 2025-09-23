// class Solution {
//     int lis(vector<int>& nums,int n,vector<int>&har,int &cnt,int i,int j){
//       if(j==n){
//         return har.length();
//       }
//       if(nums[i]<har[j]){
//         return lis(nums,n,har,cnt+1,i+1,j+1);
//       }
//       return lis(nums,n,har,cnt,i,j+1);
//     }
//     return har.length();
// public:
//     int lengthOfLIS(vector<int>& nums) {
//    int n=nums.size();
//    int i=nums[0];
//    int j=har[0];
//    vector<int>har;
//    int cnt=0;
//    return lis(nums,n,har,cnt,i,j);
//     }
// };


// class Solution {
//     int lis(vector<int>& nums, int n, int i, int j, int cnt, vector<int>& har) {
//         if (j == n) {
//             return cnt;
//         }

//         int taken = cnt;
//         if (nums[i] < nums[j]) {
//             // i ko update j se, j aage
//             taken = lis(nums, n, j, j + 1, cnt + 1, har);
//         }

//         int not_taken = lis(nums, n, i, j + 1, cnt, har);

//         return max(taken, not_taken);
//     }

// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;

//         vector<int> har; // format ke liye
//         int cnt = 1;
//         int result = 0;

//         // Try starting LIS from every index to handle first element choice
//         for (int start = 0; start < n; start++) {
//             result = max(result, lis(nums, n, start, start + 1, 1, har));
//         }

//         return result;
//     }
// };





class Solution {
    int lis(vector<int>& nums, int n, int i, int j, vector<vector<int>>& dp) {
        if (j == n) {
            return 1; 
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int taken = 0;
        if (nums[i] < nums[j]) {
            taken = 1 + lis(nums, n, j, j + 1, dp);
        }
        int not_taken = lis(nums, n, i, j + 1, dp);
        return dp[i][j] = max(taken, not_taken);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> har;
        int cnt = 1;     
        int result = 0;
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        for (int start = 0; start < n; start++) {
            result = max(result, lis(nums, n, start, start + 1, dp));
        }
        return result;
    }
};
