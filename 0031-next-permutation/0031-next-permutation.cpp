class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> arr;  // keep your arr structure

        int n = nums.size();
        int i = n - 2;

        // Step 1: find first index i such that nums[i] < nums[i+1]
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: if such i exists, find j to swap
        if (i >= 0) {
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // Step 3: reverse from i+1 to end
        int l = i + 1, r = n - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }

        // ✅ push result into arr (to follow your style)
        arr.push_back(nums);
    }
};

