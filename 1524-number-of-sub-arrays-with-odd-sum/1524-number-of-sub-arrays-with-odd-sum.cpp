class Solution {

public:
const int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0, evenCount = 1; // evenCount initialized to 1 to count the empty prefix sum
    long long prefixSum = 0, result = 0;

    for (int num : arr) {
        prefixSum += num;
        
        if (prefixSum % 2 == 0) {
            result = (result + oddCount) % MOD;
            evenCount++;
        } else {
            result = (result + evenCount) % MOD;
            oddCount++;
        }
    }
    
    return result;
    }
};