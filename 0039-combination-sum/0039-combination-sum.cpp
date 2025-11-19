class Solution {
//     private:
//     void candidate(vector<int>&candidates,int index,int target,vector<vector<int>>&ans,vector<int>ds){
//         if(target==0) {
//         ans.push_back(ds);
//         return;
//         }
//         if(index == candidates.size() || target < 0) return;
//         ds.push_back(candidates[index]);
//         candidate(candidates,index,target-candidates[index],ans,ds);
//         ds.pop_back();
//         candidate(candidates,index+1,target,ans,ds);
//     }
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//    int n=candidates.size();
//         vector<vector<int>>ans;
//         vector<int>ds;
//         int index=0;
//      int i=0;
//         candidate(candidates,index,target,ans,ds);
//         return ans;




private:
    void candidate(vector<int>& candidates, int index, int target, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        if (index == candidates.size() || target < 0) return;

        // take current element
        if (candidates[index] <= target) {
            ds.push_back(candidates[index]);
            candidate(candidates, index, target - candidates[index], ans, ds);
            ds.pop_back();
        }

        // skip current element
        candidate(candidates, index + 1, target, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
sort(candidates.begin(), candidates.end()); // pruning optimization
        vector<vector<int>> ans;
        vector<int> ds;
        candidate(candidates, 0, target, ans, ds);
        return ans;
    }
};