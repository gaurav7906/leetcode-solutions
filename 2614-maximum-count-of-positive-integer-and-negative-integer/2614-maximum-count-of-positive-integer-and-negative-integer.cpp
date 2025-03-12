class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cp=0,cn=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                cp+=1;
            }
            else if(nums[i]<0)
            cn+=1;
        }
        return max(cp,cn);
    }
};