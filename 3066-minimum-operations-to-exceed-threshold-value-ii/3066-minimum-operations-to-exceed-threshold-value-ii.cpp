class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
        int operations = 0;

        while (!minHeap.empty() && minHeap.top() < k) {
            if (minHeap.size() < 2) break;  // Safety check
            
            long long x = minHeap.top(); minHeap.pop();
            long long y = minHeap.top(); minHeap.pop();
            
            long long new_val = x * 2 + y;  // Use long long to prevent overflow
            minHeap.push(new_val);
            operations++;
        }
        
        return operations;
    }
};