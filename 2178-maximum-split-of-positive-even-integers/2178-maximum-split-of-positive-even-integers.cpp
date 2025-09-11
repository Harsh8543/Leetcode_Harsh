// class Solution {
//     void subarray(long long finalSum, vector<int>& arr, vector<int>& ans, int target, int n, int i){
//         if(i == n){
//             if(finalSum % 2 != 0){ 
//                 return;
//             }
//             if(target == 0){ 
//             }
//             return;
//         }
//         // include
//         ans.push_back(arr[i]);
//         subarray(finalSum, arr, ans, target - arr[i], n, i + 1);
//         // exclude
//         ans.pop_back();
//         subarray(finalSum, arr, ans, target, n, i + 1);
//     }
// public:
//     vector<long long> maximumEvenSplit(long long finalSum) {
//         vector<int> arr;
//         vector<int> ans;
//         int n = finalSum;
//         int target = finalSum;
//         for(int i = 2; i <= n; i += 2){
//             arr.push_back(i);
//         }

//         subarray(finalSum, arr, ans, target, arr.size(), 0);
//         vector<long long> result;
//         for(int x : ans) result.push_back(x);
//         return result;
//     }
// };

// class Solution {
//     void subarray(long long finalSum, vector<int>& arr, vector<int>& ans, int target, int n, int i){
//         if(finalSum % 2 != 0) return; // odd case -> no answer

//         long long sum = 0;
//         for(int j=0; j<n; j++){
//             if(sum + arr[j] <= target){
//                 ans.push_back(arr[j]);
//                 sum += arr[j];
//             } else {
//                 // adjust last element
//                 ans.back() += (target - sum);
//                 sum = target;
//                 break;
//             }
//         }
//     }
// public:
//     vector<long long> maximumEvenSplit(long long finalSum) {
//         vector<int> arr;
//         vector<int> ans;
//         int n = finalSum;
//         int target = finalSum;

//         for(int i = 2; i <= n; i += 2){
//             arr.push_back(i);
//         }

//         subarray(finalSum, arr, ans, target, arr.size(), 0);

//         vector<long long> result;
//         for(int x : ans) result.push_back(x);
//         return result;
//     }
// };

class Solution {
    void subarray(long long finalSum, vector<long long>& ans){
        if(finalSum % 2 != 0) return; // odd case -> no solution

        long long sum = 0;
        for(long long i = 2; i <= finalSum; i += 2){
            if(sum + i <= finalSum){
                ans.push_back(i);
                sum += i;
            } else {
                // adjust last element
                ans.back() += (finalSum - sum);
                break;
            }
        }
    }

public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        subarray(finalSum, ans);
        return ans;
    }
};


