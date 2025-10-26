class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 2) {
            v[i] = nums[i + 1];
            v[i + 1] = nums[i];
        }
        return v;
    }
};