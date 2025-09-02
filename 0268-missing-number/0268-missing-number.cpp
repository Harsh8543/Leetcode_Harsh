class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int i=0;
        int ans=n;
        sort(nums.begin(),nums.end());
        while(i<n){
            if(nums[i]==cnt){
                i++;
                cnt++;
            }
            else{
                ans=cnt;
               break;
            }
        }
        return ans;
    }
};