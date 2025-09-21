class Solution {
public:
void solve(vector<int>& nums,int start, vector<vector<int>>&v){
        if(start==nums.size()-1){
            v.push_back(nums);
            return;
        }
        set<int>mp;
        for(int i=start;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                mp.insert(nums[i]);
                swap(nums[i],nums[start]);
                solve(nums,start+1,v);
                swap(nums[i],nums[start]);
            }
        }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>> v;
         solve(nums,0,v);
         return v;
    }
};