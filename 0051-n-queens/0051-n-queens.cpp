class Solution {
public:
    void queen(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&uperdignal,vector<int>&lowerd,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++)
        {
            if(leftrow[row]==0 && uperdignal[n-1+col-row]==0 && lowerd[row+col]==0)
            {
                board[row][col]='Q';
                leftrow[row]=1;
                uperdignal[n-1+col-row]=1;
                lowerd[row+col]=1;
                queen(col+1,board,ans,leftrow,uperdignal,lowerd,n);
                board[row][col]='.';
                leftrow[row]=0;
                uperdignal[n-1+col-row]=0;
                lowerd[row+col]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
     {
        string s(n,'.');
        vector<string>board(n);
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int>leftrow(n,0),uperdignal(2*n-1,0),lowerd(2*n-1,0);
        queen(0,board,ans,leftrow,uperdignal,lowerd,n);
        return ans;
    }
};