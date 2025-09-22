class Solution {
    int robbery(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int curr, prev = max(nums[0], nums[1]), prev2 = nums[0];
        for (int i = 2; i < n; i++) {
            curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> arr1;
        vector<int> arr2;
        for (int i = 0; i < n - 1; i++) {
            arr1.push_back(nums[i]);
        }
        for (int i = 1; i < n; i++) {
            arr2.push_back(nums[i]);
        }
        int curr1 = robbery(arr1);
        int curr2 = robbery(arr2);
        return max(curr1, curr2);
    }
};
