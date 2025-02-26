class Solution {
public:
    int getmax(vector<int>&nums){
        int n=nums.size();
       int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
    int getmin(vector<int>&nums){
        int n=nums.size();
       int maxi=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=min(maxi,sum);
            if(sum>0){
                sum=0;
            }
        }
        return maxi;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=getmax(nums);
        int mini=getmin(nums);
        return max(maxi,abs(mini));
    }
};