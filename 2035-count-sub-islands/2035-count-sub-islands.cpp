class Solution {
public:
    bool dfs(int row, int col, int n, int m, vector<vector<int>>& vis, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vis[row][col] = 1;
         bool issubiland=true;
        if(grid1[row][col]==0){
             issubiland=false;
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid2[nrow][ncol] == 1 ) {
                if(!dfs(nrow, ncol, n, m, vis, grid1, grid2))
                issubiland=false;
            }
        }
        return issubiland ;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid2[i][j] == 1) {
                    if (dfs(i, j, n, m, vis, grid1, grid2)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
