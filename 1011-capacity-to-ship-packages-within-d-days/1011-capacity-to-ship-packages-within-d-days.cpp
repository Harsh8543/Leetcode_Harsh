// class Solution {
//     public:
//             int maxi = INT_MIN;
//         int n = weights.size();
//         for(int i=0;i<n;i++){
//             maxi=max(maxi,weights[i]);
//         }
//         return maxi;
//     }
//     long long int calculateTotaldays(vector<int> &weights, int mid){
//         long long int totald=0;
//         long long int sum=0;
//         int n = weights.size();
//         for(int i=0;i<n;i++){
//             if(sum<=mid){
//                 sum=sum+weights[i];
//             }
//             totalh +=ceil((double)(sum)/(double)(mid));
//         }
//         return totald;
//     }
//     int shipWithinDays(vector<int>& weights, int days) {
//         int low=1,high=findMax(weights);
//         while(low<=high){
//             int mid=(low+high)/2;
//             long long int totald = calculateTotalHours(weights, mid);
//             if(totald <= h){
//                 high = mid-1;
//             } 
//             else{
//                 low = mid+1;   
//             }
//         }
//         return low;
//     }
// };
class Solution {
public:
    int findMax(vector<int> &weights) {
        int maxi = INT_MIN;
        int n = weights.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, weights[i]);
        }
        return maxi;
    }

    long long int calculateTotaldays(vector<int> &weights, int mid) {
        long long int totald = 0;
        long long int sum = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++) {
            if (sum + weights[i] <= mid) {
                sum += weights[i];
            } else {
                totald += ceil((double)(sum) / mid);
                sum = 0;
                i--; 
            }
        }
        if (sum > 0) {
            totald += ceil((double)(sum) / mid);
        }

        return totald;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = findMax(weights);
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = (low + high) / 2;
            long long int totald = calculateTotaldays(weights, mid);
            if (totald <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
