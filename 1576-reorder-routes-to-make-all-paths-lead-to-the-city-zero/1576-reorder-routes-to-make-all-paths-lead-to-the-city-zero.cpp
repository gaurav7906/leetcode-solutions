class Solution {
public:
    int count = 0;
    void dfs(int src, int parent, vector<vector<pair<int, int>>>& adj) {
        for (auto& nbr : adj[src]) {
            int des = nbr.first;
            int eze = nbr.second;
            if (des != parent) {
                if (eze == 1) count++;
                dfs(des, src, adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        count = 0;
        for (auto& it : connections) {
            int a = it[0], b = it[1];
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 0});
        }
        dfs(0, -1, adj);
        return count;
    }
};
