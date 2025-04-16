class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // set<int>s;
        // for(int i=0;i<nums.size();i++){
        //     s.insert(nums[i]);
        // }
        // vector<int> gir(s.begin(), s.end());
        // int j=gir.size()-1;
        // int cnt=1;
        // while(j>0){
        //     if(cnt==k){
        //         return gir[j];
        //     }
        //     else{
        //         cnt++;
        //         j--;
        //     }
        // }return 0;




        // set<int> s;
        // for (int i = 0; i < nums.size(); i++) {
        //     s.insert(nums[i]);
        // }

        // // Convert set to vector to access elements by index
        // vector<int> sorted(s.begin(), s.end());

        // // Now we access from the back (largest elements)
        // int j = sorted.size() - 1;
        // int cnt = 1;

        // while (j >= 0) {
        //     if (cnt == k) {
        //         return sorted[j];
        //     } else {
        //         cnt++;
        //         j--;
        //     }
        // }

        // return 0;

     sort(nums.begin(),nums.end());

        int j = nums.size() - 1;
        int cnt = 1;

        while (j >= 0) {
            if (cnt == k) {
                return nums[j];
            } else {
                cnt++;
                j--;
            }
        }

        return 0;
    }
     
};