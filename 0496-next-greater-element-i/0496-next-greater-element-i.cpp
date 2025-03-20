class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums2.size();
        vector<int>storegreater(n,-1);
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums2[i]<nums2[j]){
                storegreater[i]=nums2[j];
                break;
            }
        }
       }
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
        mp[nums2[i]]=storegreater[i];
       }
       int n1=nums1.size();
       vector<int>ans(n1,-1);
       for(int i=0;i<n1;i++){
        ans[i]=mp[nums1[i]];
       }
       return ans;
    }
};