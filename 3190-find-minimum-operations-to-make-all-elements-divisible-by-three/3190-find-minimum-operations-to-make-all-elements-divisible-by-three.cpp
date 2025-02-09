class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int i=0;
        int cont=0;
     for(i=0;i<nums.size();i++){
       
           if(nums[i]%3==1){
             nums[i]-1;
            cont++;
        }
          if(nums[i]%3==2){
            nums[i]-2;
            cont++;
        }
     }
     return cont;
    }
};