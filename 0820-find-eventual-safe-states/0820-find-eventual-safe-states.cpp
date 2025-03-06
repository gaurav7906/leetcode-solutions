class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathvis) {
        vis[node] = 1;
        pathvis[node] = 1;
        
        for (auto &it : graph[node]) {
            if (!vis[it]) {
                if (dfs(it, graph, vis, pathvis)) {
                    return true;
                }
            } else if (pathvis[it]) {
                return true;
            }
        }
        
        pathvis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0), pathvis(n,0);
        vector<int> ans;
        for (int node = 0; node < n; node++) {
            if (!dfs(node, graph, vis, pathvis)) {
                ans.push_back(node);
            }
        }
        return ans;
    }
};
