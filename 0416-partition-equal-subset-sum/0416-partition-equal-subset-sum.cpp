class Solution {
public:
    bool yestheycan(int index,int sum,int target,vector<int>& nums, vector<vector<int>>&dp)
    {
        if(sum==target)
        return true;
         if (sum > target || index == nums.size()) 
            return false;
        if(dp[index][sum]!=-1)
        return dp[index][sum];
            bool inc=yestheycan(index+1,sum+nums[index],target,nums,dp);
            bool exc= yestheycan(index+1,sum,target,nums,dp);
            dp[index][sum]=inc||exc;
       return  dp[index][sum];
    }
    bool canPartition(vector<int>& nums)
     {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int n=nums.size();
         int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        if(sum%2!=0)
        return false;
        else{
              return yestheycan(0,0,target,nums,dp);
        }
     
    }
};
