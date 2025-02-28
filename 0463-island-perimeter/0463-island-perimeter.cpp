class Solution {
public:
    // void dfs(int i ,int j,vector<vector<int>>& grid,int count)
    // {
    //     int drow[]={-1,0,1,0};
    //     int dcol[]={0,1,0,-1};
    //     if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)
    //     {
    //         count++;
    //         return;
    //     }
    //     if(grid[i][j]!=1)
    //     return ;
    //     grid[i][j]==2;
    // }
   int islandPerimeter(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0)); // Initialize vis with 0s
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    int cnt = 0;
    
    // Pushing all 1s into the queue and marking them as visited
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                q.push({i, j});
                vis[i][j] = 1; // Mark as visited
            }
        }
    }

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m || grid[nrow][ncol] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

};