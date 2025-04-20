class Solution {
public:
    int find(vector<int>& nums, int index, int target) {
         if(index==nums.size()) {
            if (target==0) return 1;
            return 0;
        }
        return find(nums,index+1,target-nums[index]) + 
               find(nums,index+1,target+nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
         return find(nums,0,target);
    }
};