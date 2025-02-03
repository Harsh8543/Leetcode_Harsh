class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
          if(nums.size() == 1) return true;
        bool flag  = true;
        for(int i=0; i<nums.size()-1;i++){
            if(((nums[i]%2 == 0) && (nums[i+1]%2 == 0)) || ((nums[i]%2 != 0) && (nums[i+1]%2 != 0))){
                flag = 0;
                break;
            }
        }
        if(flag) return 1;
        return 0;
    }
};