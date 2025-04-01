class Solution {
public:
    int majorityElement(vector<int>& nums)
     {
         int n=nums.size();
         int el;
         int ct=0;
         for(int i=0;i<n;i++)
         {
             if(ct==0)
             {
                 el=nums[i];
                 ct=1;
             }
             else if(nums[i]==el)
             {
                 ct++;
             }
             else
             ct--;
         }
         ct=0;
         for(int i=0;i<n;i++)
         {
             if(nums[i]==el)
             {
                 ct++;
             }
         }
         if(ct>n/2)
         return el;
         else 
         return -1;
    }
};