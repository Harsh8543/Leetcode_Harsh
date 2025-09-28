class Solution {
    public long splitArray(int[] nums) {
        int n = nums.length;
        long left[] = new long[n];
        left[0] = nums[0];
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1]){
                left[i] = left[i-1] + nums[i];
            }
            else break;
        }
        long right[] = new long[n];
        right[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                right[i] = right[i+1] + nums[i];
            }
            else break;
        }
        long ans  = Long.MAX_VALUE;
        for(int i=n-1;i>0;i--){
            if(left[i-1]!=0 && right[i]!=0) ans = Math.min(ans,Math.abs(right[i]-left[i-1]));
        }
        return ans== Long.MAX_VALUE ? -1 : ans;
    }
}