class Solution {
public:
    void subway(int index,vector<int>& nums,vector<int>& data,vector<vector<int>>&ans)
    {
            ans.push_back(data);
        
        for(int i=index;i<nums.size();i++)
        {
            if(i>index && nums[i]==nums[i-1] )
            continue;
            data.push_back(nums[i]);
            subway(i+1,nums,data,ans);
            data.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<int>data;
        vector<vector<int>> ans;
        subway(0,nums,data,ans);
        return ans;
    }
};