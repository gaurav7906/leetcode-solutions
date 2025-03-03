class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int small=0,equal=0;
        for(int i =0;i<n;i++){
            if(nums[i]<pivot){
                small++;
            }
            else if (nums[i]==pivot){
                equal++;
            }
        }
        vector<int>ans(n);
        int l=0;
        int j=small;
        int k=small+equal;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans[l++]=nums[i];
            }
            else if (nums[i]==pivot){
                ans[j++]=nums[i];
            }
            else{
                ans[k++]=nums[i];
            }
        }
        return ans;
    }
};