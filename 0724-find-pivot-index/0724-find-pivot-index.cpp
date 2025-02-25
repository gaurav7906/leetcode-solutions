class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int rem=0;
        for(int i=0;i<nums.size();i++){
            rem+=nums[i];
            sum=sum-nums[i];
            if(rem-nums[i]==sum){
                return i;
            }
        }
        return -1;
    }
};