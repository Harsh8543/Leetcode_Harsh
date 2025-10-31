class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<bool>& visited, vector<bool> path) {
        if (visited[node]) return true;
        if (path[node]) return false;

        path[node] = true;

        for (int i : adj[node]) {
            if (!dfs(i, adj, visited, path)) {
                return false;
            }
        }

        visited[node] = true;
        path[node] = false;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);

        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(i, adj, visited, path)) {
                    return false;
                }
            }
        }

        return true;
    }
};