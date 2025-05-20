class Solution {
public:
    int findMax(vector<int> &v){
        int maxi = INT_MIN;
        int n = v.size();
        for(int i =0; i<n; i++){
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }
    long long int calculateTotalHours(vector<int> &v, int hourly){
        long long int totalh=0;
        int n = v.size();
        for(int i=0;i<n;i++){
            totalh += ceil((double)(v[i]) / (double)(hourly));
        }
        return totalh;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        int low = 1, high = findMax(v);
        while(low<=high){
            int mid=(low+high)/2;
            long long int totalh = calculateTotalHours(v, mid);
            if(totalh <= h){
                high = mid-1;
            }
            else{
                low = mid+1;   
            }
        }
        return low;
    }
};
