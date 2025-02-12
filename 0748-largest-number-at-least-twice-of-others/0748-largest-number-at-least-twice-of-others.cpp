class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxindx=-1;
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxindx=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(maxindx==i)
            continue;
            else if(maxi<2*nums[i]){
                return -1;
            }
        }
        return maxindx;
    }
};