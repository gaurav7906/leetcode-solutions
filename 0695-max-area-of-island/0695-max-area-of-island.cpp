class Solution {
public:
    void bfs(int row,int col ,vector<vector<int>>& grid,vector<vector<int>>& vis,int & count){
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        count=1;
         queue<pair<int,int>>q;
         q.push({row,col});
         while(!q.empty()){
            auto node=q.front();
            int row=node.first;
            int col=node.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    count+=1;
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }

         }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        int maxcount=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    vis[i][j]=1;
                    count=1;
                    bfs(i,j,grid,vis,count);
                    maxcount=max(count,maxcount);
                }
            }
        }
        return maxcount;
    }

};