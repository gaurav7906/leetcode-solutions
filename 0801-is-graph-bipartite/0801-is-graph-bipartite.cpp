class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i); 
            }
        }

        queue<int> q;
        vector<int> colr(n, -1);

        for (int i = 0; i < n; i++)
         {
            if (colr[i] == -1) 
            {
                q.push(i);
                colr[i] = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto neighbor : adj[node]) {
                        if (colr[neighbor] == -1) {
                            colr[neighbor] = !colr[node];
                            q.push(neighbor);
                        } else if (colr[neighbor] == colr[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
