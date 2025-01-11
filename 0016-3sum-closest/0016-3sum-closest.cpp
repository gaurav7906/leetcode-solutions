class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int closestsum=nums[0]+nums[1]+nums[2];
        int mindi=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
               if(sum==target)
               return sum;
               else if(sum<target)
               j++;
               else
               k--;
               int curdi=abs(sum-target);
               if(curdi<mindi)
               {
                   mindi=curdi;
                   closestsum=sum;
               }
            }
        }
        return closestsum;
    }
};