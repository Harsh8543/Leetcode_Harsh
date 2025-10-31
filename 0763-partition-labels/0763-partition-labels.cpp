class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;
        for(int i = 0; i < s.size(); i++){
            if(mp2.count(s[i]) == 0) mp2[s[i]] = i;
            mp[s[i]]++;

        }
        vector<int>v;
        int t = 0;
        for(int i = 0; i < s.size(); i++){
            if(mp2[s[i]] == i)t += mp[s[i]];
            t--;
            mp[s[i]]--;
            if(t == 0 && mp[s[i]] == 0){
                v.push_back(i+1);
            }
        }
        int prev = 0;
        for(int i = 0; i < v.size(); i++){
            int temp = v[i];
            v[i] -= prev;
            prev = temp;
        }
        return v;
    }
};