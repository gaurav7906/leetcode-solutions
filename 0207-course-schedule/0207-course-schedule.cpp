class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathvis, vector<vector<int>>& adj) {
        vis[node] = 1;
        pathvis[node] = 1;
        for (auto &nbr : adj[node]) {
            if (!vis[nbr]) {
                if (dfs(nbr, vis, pathvis, adj)) {
                    return true;
                }
            } else if (pathvis[nbr] == 1) {
                return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for (auto &it : prerequisites) {
            int src = it[0];
            int des = it[1];
            adj[des].push_back(src);
        }
        vector<int> vis(n, 0), pathvis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathvis, adj)) {
                    return false;
                }
            }
        }
        return true; 
    }
};
