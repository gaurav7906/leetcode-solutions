class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> finalans;
        unordered_map<string,vector<string>>mp;
        for (int i = 0; i < n; i++) {
           string temp1 = strs[i];
           sort(temp1.begin(),temp1.end());
           mp[temp1].push_back(strs[i]);
        }
        for (auto & it : mp ){
            finalans.push_back(it.second);
        }
        return finalans;
    }
    //although this solution is correct biut it is giving tle for test case the thing is we are keeping a track of visited array so that once we loop we skip the already grouped string.

};
