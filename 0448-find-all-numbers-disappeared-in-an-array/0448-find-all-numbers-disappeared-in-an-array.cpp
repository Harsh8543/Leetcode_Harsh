class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
            sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> har;
        int i = 0;
        int j = 1; // expected number from 1 to n
        while (i < n) {
            if (nums[i] == j) {
                i++;
                j++;
            }
            else if (nums[i] < j) {
                // duplicate or too small, move forward
                i++;
            }
            else {
                // nums[i] > j → j is missing
                har.push_back(j);
                j++;
            }
        }
        // After array ends, remaining numbers from j to n are missing
        while (j <= n) {
            har.push_back(j);
            j++;
        }

        return har;
    }
};