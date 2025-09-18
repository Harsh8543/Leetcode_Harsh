class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(auto it : arr){
            mp[it]++;
        }

        vector<int> har;
        for(auto it : mp){
            har.push_back(it.second);
        }
        sort(har.begin(), har.end(), greater<int>());
        int sum = 0, cnt = 0;
        for(int i = 0; i < har.size(); i++){
            sum += har[i];
            cnt++;
            if(sum >= n/2){
                return cnt;
            }
        }
        return cnt;
    }
};
