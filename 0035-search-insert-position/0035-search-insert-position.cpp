class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
     {
         int n=nums.size();
         int l=0,h=n-1;
         int mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(nums[mid]==target)
            {
            return mid;
            }
           else if(target<nums[mid])
            {
              h=mid-1;
            }
            else
            l=mid+1;
        }
        return l;
    }
};