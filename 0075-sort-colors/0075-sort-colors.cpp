class Solution {
public:
    void sortColors(vector<int>& nums) {
         int low = 0, mid = 0, high = nums.size() - 1;
    
    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                std::swap(nums[low++], nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                std::swap(nums[mid], nums[high--]);
                break;
        }
    }
    }
};