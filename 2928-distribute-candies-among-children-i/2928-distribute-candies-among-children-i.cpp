class Solution {
private:
    void dfs(int child, int remaining, vector<int>& sol, vector<vector<int>>& ans, int limit) {
        if (child == 3) {
            if (remaining == 0) ans.push_back(sol);
            return;
        }

        for (int i = 0; i <= min(limit, remaining); i++) {
            sol.push_back(i);             
            dfs(child + 1, remaining - i, sol, ans, limit);
            sol.pop_back();  
        }
    }

public:
    int distributeCandies(int n, int limit) {
        vector<vector<int>> ans;
        vector<int> sol;
        dfs(0, n, sol, ans, limit);
        return ans.size();
    }
};
