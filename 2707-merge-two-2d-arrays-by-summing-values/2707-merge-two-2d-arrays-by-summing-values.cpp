class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;
        int n =nums1.size();
        for(auto & it : nums1){
           int id=it[0];
           int val=it[1];
           mp[id]=val;
        }
        for(auto & it : nums2){
            int id=it[0];
            int val=it[1];
            if(mp.find(id)!=mp.end()){
                mp[id]+=val;
            }
            else{
                mp[id]=val;
            }
        }
        vector<vector<int>>ans;
        for(auto & it:mp){
            int id=it.first;
            int val=it.second;
            vector<int>temp;
            temp.push_back(id);
            temp.push_back(val);
            ans.push_back(temp);
        }
        return ans ;
    }
};