class Solution {
private:
    void Nonsubsequence(vector<int>& nums, int index, vector<vector<int>>& ans, vector<int> op) {
        if (op.size() >= 2) {
            ans.push_back(op);
        }

        unordered_set<int> used;  
        for (int j = index; j < nums.size(); j++) {
            if ((op.empty() || nums[j] >= op.back()) && used.find(nums[j]) == used.end()) {
                used.insert(nums[j]);
                op.push_back(nums[j]);
                Nonsubsequence(nums, j + 1, ans, op);
                op.pop_back();  // backtrack
            }
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        Nonsubsequence(nums, 0, ans, op);
        return ans;
    }
};
