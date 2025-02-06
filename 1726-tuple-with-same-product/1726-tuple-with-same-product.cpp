class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
 unordered_map<int, int> productMap;
        int count = 0;
        int n = nums.size();
        
        // Store the count of each product
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productMap[product]++;
            }
        }
        
        // Calculate the number of valid tuples
        for (auto& entry : productMap) {
            int pairCount = entry.second;
            if (pairCount > 1) {
                count += pairCount * (pairCount - 1) * 4;
            }
        }
        
        return count;
    }
};