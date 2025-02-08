class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size(); // No duplicates if size <= 2
        
        int write = 1; // Write pointer
        int count = 1; // Count of current element
        
        for (int read = 1; read < nums.size(); ++read) {
            if (nums[read] == nums[read - 1]) {
                // Increment count if current element matches previous
                count++;
            } else {
                // Reset count for a new element
                count = 1;
            }
            
            // Write the current element if count <= 2
            if (count <= 2) {
                nums[write] = nums[read];
                write++;
            }
        }
        
        return write;
    }
};