class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        int n=arr.size();
        int m=arr.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                dp[i][j]=2;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
               int sum=arr[i]+arr[j];
                if(mp.find(sum)!=mp.end()){
                   int k=mp[sum];
                    dp[j][k]=dp[i][j]+1;
                }
            }
        }
        int maxi=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              
                    maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi>=3?maxi:0;
    }
};