class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        int n=grid.size();
        int m=grid[0].size();
        int repeat;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp.find(grid[i][j])!=mp.end()){
                    repeat=grid[i][j];
                }
                else{
                    mp[grid[i][j]]=1;
                }
            }
        }
        int count=1;
        int missing=0;
        for(auto&it :mp){
            if(mp.find(count)!=mp.end()){
                missing=count;
                count+=1;
            }
            else{
                missing=count;
                return {repeat,missing};
            }
        }
        return {repeat,missing+1};
    }
};