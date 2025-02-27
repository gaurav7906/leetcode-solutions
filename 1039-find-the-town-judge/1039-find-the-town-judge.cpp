class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int>st;
        vector<int>vis(n+1,0);
        for(auto & it : trust){
            int child=it[0];
            int parent=it[1];
            st.insert(child);
                vis[parent]+=1;
            }   
        for(int i=1;i<=n;i++){
            if(vis[i]==n-1 && st.find(i)==st.end()){
                return i;
            }
        }    
        return -1;
    }
};