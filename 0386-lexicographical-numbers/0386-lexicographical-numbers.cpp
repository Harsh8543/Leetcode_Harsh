class Solution {
public:
   void solve(int num , int n , vector<int> &ans){
        ans.push_back(num);

        for(int i = 0 ; i <= 9 ; i++){
            int new_num = num*10 + i;
            if(new_num > n){
                return;
            }
            solve(new_num , n , ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1 ; i <= 9 ; i++){
            if(i <= n)
                solve(i ,  n  , ans);
        }

        return ans;
    }
};