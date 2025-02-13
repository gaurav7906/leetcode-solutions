class Solution {
public:
    bool isArraySpecial(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int nums1=nums[i]%2;
            int nums2=nums[i+1]%2;
            if(nums1==nums2){
                return false;
            }
        }
        return true;
    }
};