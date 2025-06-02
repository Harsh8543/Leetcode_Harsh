class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>v;
        vector<pair<int,int>>p;
        for(int i=0;i<intervals.size();i++){
            p.push_back({intervals[i][0],intervals[i][1]});
        }
        p.push_back({newInterval[0],newInterval[1]});
        sort(p.begin(),p.end());
        int l=p[0].first,r=p[0].second;
        for(int i=1;i<p.size();i++){
            if(r>=p[i].first){
                l=min(l,p[i].first);
                r=max(r,p[i].second);
            }
            else{
                v.push_back({l,r});
                l=p[i].first;
                r=p[i].second;
            }
        }
        v.push_back({l,r});
        return v;
    }
};