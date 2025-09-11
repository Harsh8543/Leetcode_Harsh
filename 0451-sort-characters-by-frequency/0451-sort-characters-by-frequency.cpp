class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;   
        }
        vector<pair<int,char>> arr;
        for(auto it : mp){
            arr.push_back({it.second, it.first}); 
        }
        sort(arr.begin(), arr.end());  
        int n = arr.size();
        string ans = "";
        int i = n-1;
        while(i >= 0){
            for(int j=0;j<arr[i].first;j++){
                ans += arr[i].second;  
            }
            i--;
        }
        return ans;
    }
};
