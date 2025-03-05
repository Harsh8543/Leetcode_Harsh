class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        vector<int> harsh;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                harsh.push_back(nums1[i]);
                i++;
            } else {
                harsh.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m) {
            harsh.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            harsh.push_back(nums2[j]);
            j++;
        }
        int totalSize = m + n;
        if (totalSize % 2 == 1) {
            return harsh[totalSize / 2];
        } else {
            return (harsh[totalSize / 2 - 1] + harsh[totalSize / 2]) / 2.0;
        }
        
    }
};