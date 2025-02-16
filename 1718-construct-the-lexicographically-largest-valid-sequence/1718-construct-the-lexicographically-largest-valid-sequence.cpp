class Solution {
public:

bool backtrack(vector<int>& res, vector<bool>& used, int n, int index) {
    if (index == res.size()) return true;
    
    if (res[index] != 0) return backtrack(res, used, n, index + 1);
    
    for (int i = n; i >= 1; --i) {
        if (used[i]) continue;
        
        if (i == 1) {
            res[index] = 1;
            used[i] = true;
            if (backtrack(res, used, n, index + 1)) return true;
            res[index] = 0;
            used[i] = false;
        } else {
            int nextPos = index + i;
            if (nextPos < res.size() && res[nextPos] == 0) {
                res[index] = res[nextPos] = i;
                used[i] = true;
                if (backtrack(res, used, n, index + 1)) return true;
                res[index] = res[nextPos] = 0;
                used[i] = false;
            }
        }
    }
    return false;
}
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
    vector<int> res(size, 0);
    vector<bool> used(n + 1, false);
    backtrack(res, used, n, 0);
    return res;
    }
};