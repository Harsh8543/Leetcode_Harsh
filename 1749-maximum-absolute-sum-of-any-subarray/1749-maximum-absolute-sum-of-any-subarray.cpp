class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0, currMax = 0, currMin = 0;

    for (int num : nums) {
        currMax = max(num, currMax + num);  // Kadane's for max subarray sum
        currMin = min(num, currMin + num);  // Kadane's for min subarray sum

        maxSum = max(maxSum, currMax);
        minSum = min(minSum, currMin);
    }

    return max(maxSum, abs(minSum));
    }
};