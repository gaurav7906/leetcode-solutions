class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
          int n = grid.size();
         if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
            if (n-1==0)
            return 1;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0]=1;
        q.push({1, {0,0}});

        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty()) {
            auto it = q.front();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 &&
                    dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = 1 + dis;
                    if (nrow == n-1 && ncol ==n-1)
                        return dis + 1;
                    q.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid)
//      {
//         int n=grid.size();
//         queue<pair<int,pair<int,int>>> q;
//         vector<vector<int>>dist(n,vector<int>(n,1e9));
//         pair<int,int>source={0,0};
//         pair<int,int>dest={n-1,n-1};
//         dist[source.first][source.second]=0;//may change later
//         q.push({0,{source.first,source.second}});
//         int drow[]={-1,-1,0,1,1,1,0,-1};
//         int dcol[]={0,1,1,1,0,-1,-1,-1};
//         while(!q.empty())
//         {
//             auto it=q.front();
//             int dis=it.first;
//             int row=it.second.first;
//             int col=it.second.second;
//             for(int i=0;i<8;i++)
//             {
//                 int nrow=row+drow[i];
//                 int ncol=col+dcol[i];
//                 if(nrow>=0 && nrow<n&& ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol])
//                 {
//                     dist[nrow][ncol]=1+dis;
//                     if(nrow==dest.first && ncol==dest.second)
//                         return dis+1;
//                         q.push({1+dis,{nrow,ncol}});
//                 }
//             }
//         }
//         return -1;
//     }
// };
// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid)
//      {
//         queue<pair<int,int>> q;
//         int n = grid.size();
//         if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
//             return -1;
//         if(n-1 == 0)
//             return 1;
//         grid[0][0] = 1;  
//         q.push({0,0});
//         int count = 0;
//         int flag = 0;
//         vector<int> r = {0,1,-1,0,1,-1,1,-1};
//         vector<int> c = {1,0,0,-1,1,1,-1,-1};
//         while(!q.empty())
//         {
//             int size = q.size();
//             queue<pair<int,int>> temp;
//             count++;
//             while(size--)
//             {
//                 int row = q.front().first;
//                 int col = q.front().second;
//                 q.pop();
//                 for(int i = 0; i<8; i++)
//                 {
//                     int x = row + r[i], y = col + c[i];
//                     if(x == n-1 && y == n-1)
//                     {
//                         flag = 1;
//                         count++;
//                         break;
//                     }
//                     if(x >= 0 && y >= 0 && x < n && y < n)
//                     {
//                         if(grid[x][y] == 0)
//                         {
//                             temp.push({x,y});
//                             grid[x][y] = 1;
//                         }
//                     }
//                 }
//                 if(flag == 1)
//                     break;
//             }
//             q = temp;
//             if(flag == 1)
//                 break;
//         }
//         if(flag == 0)
//             return -1;
//         return count;
//     }
// };
