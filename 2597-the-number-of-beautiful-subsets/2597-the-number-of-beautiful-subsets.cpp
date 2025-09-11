// class Solution {
//     void count(vector<int>& nums,int n,int index,int k,int &cnt,vector<int>&op,vector<vector<int>>&ans){
//         if(index==n){
//             if(op.size()==1){ 
//                 ans.push_back(op);
//                 cnt++;
//             }
//             else if(op.size()==2){  
//                 if(abs(op[1]-op[0])!=k){  
//                     ans.push_back(op);
//                     cnt++;
//                 }
//             }
//             else if(op.size()>2){  
//                 return;
//             }
//             return;
//         }

//         // include
//         op.push_back(nums[index]);
//         count(nums,n,index+1,k,cnt,op,ans);

//         // exclude
//         op.pop_back();
//         count(nums,n,index+1,k,cnt,op,ans);
//     }

// public:
//     int beautifulSubsets(vector<int>& nums, int k) {
//         int n=nums.size();
//         vector<vector<int>> ans;
//         vector<int> op;
//         int index=0;
//         int cnt=0;
//         count(nums,n,index,k,cnt,op,ans);
//         return cnt;
//     }
// };


class Solution {
    void count(vector<int>& nums,int n,int index,int k,int &cnt,vector<int>&op,vector<vector<int>>&ans){
        if(index==n){
            if(op.size()>=1){   
                bool ok = true;
                for(int i=0;i<op.size();i++){
                    for(int j=i+1;j<op.size();j++){
                        if(abs(op[i]-op[j])==k){ 
                            ok = false;
                            break;
                        }
                    }
                    if(!ok) break;
                }
                if(ok){
                    ans.push_back(op);
                    cnt++;
                }
            }
            return;
        }

        // include
        op.push_back(nums[index]);
        count(nums,n,index+1,k,cnt,op,ans);

        // exclude
        op.pop_back();
        count(nums,n,index+1,k,cnt,op,ans);
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> op;
        int index=0;
        int cnt=0;
        count(nums,n,index,k,cnt,op,ans);
        return cnt;
    }
};

