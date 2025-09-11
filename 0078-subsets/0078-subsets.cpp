class Solution {
    void subset1(vector<int>& nums,int n,int index,vector<int>&op,vector<vector<int>>&ans){
        if(index==n){
        ans.push_back(op);
        return;
        }
        op.push_back(nums[index]);
        subset1(nums,n,index+1,op,ans);
        op.pop_back();
        subset1(nums,n,index+1,op,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>op;
       int n=nums.size();
       int index=0;
       subset1(nums,n,index,op,ans);
       return ans;
    }
};