class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int j=0;
        int mazlen=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
                while(sum>=target){
                     mazlen=min(mazlen,i-j+1);
                     sum-=nums[j];
                     j+=1;
            }
            }
        return mazlen==INT_MAX?0:mazlen;
    }
};