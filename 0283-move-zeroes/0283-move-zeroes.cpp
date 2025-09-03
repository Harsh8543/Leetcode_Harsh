class Solution {
public:
    void moveZeroes(vector<int>& nums) {
           int n = nums.size(); 
        int i = 0;
        int j = 0;

        while (j < n) {  
            if (nums[i] == 0 && nums[j] == 0) {
                j++;
            } else {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
        //  unordered_map<int,int> mp;
        // for (int x : nums) {
        //     mp[x]++;
        // }
        // for (auto& p : mp) {
        //     if (p.second == 1) {
        //         return p.first;
        //     }
        // }
        // return -1;
    }
};