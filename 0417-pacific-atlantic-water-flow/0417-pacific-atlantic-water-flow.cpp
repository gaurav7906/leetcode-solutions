class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& vis, int prevheight) {
        if (row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size() || vis[row][col] == 1 || heights[row][col] < prevheight)
            return;
        
        vis[row][col] = 1; // Mark visited before exploring
        dfs(row - 1, col, heights, vis, heights[row][col]);  // Up
        dfs(row, col + 1, heights, vis, heights[row][col]);  // Right
        dfs(row + 1, col, heights, vis, heights[row][col]);  // Down
        dfs(row, col - 1, heights, vis, heights[row][col]);  // Left
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> vis1(n, vector<int>(m, 0));
        vector<vector<int>> vis2(n, vector<int>(m, 0));
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            dfs(0, i, heights, vis1, heights[0][i]);       
            dfs(n - 1, i, heights, vis2, heights[n - 1][i]); 
        }
        for (int i = 0; i < n; i++) {
            dfs(i, 0, heights, vis1, heights[i][0]);       
            dfs(i, m - 1, heights, vis2, heights[i][m - 1]); 
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis1[i][j] && vis2[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
