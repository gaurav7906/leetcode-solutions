class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n%2!=0) return false;
        for(int i=1;i<n;i+=2){
            if(nums[i]!=nums[i-1])
            return false;
        }
        return true;
    }
};