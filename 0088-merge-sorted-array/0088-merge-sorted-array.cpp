class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         int i=0;  
        int j=0;  
        vector<int> harsh;
        while (i<m&&j<n) {
            if (nums1[i]<nums2[j]) {
                harsh.push_back(nums1[i]);
                i++;
            }
            else{
                harsh.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m) {
            harsh.push_back(nums1[i]);
            i++;
        }
        while(j<n) {
            harsh.push_back(nums2[j]);
            j++;
        }
        for(int i=0;i<m+n;i++) {
            nums1[i]=harsh[i];
        }
    }
};



