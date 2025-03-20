class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n2=nums2.size();
        stack<int>st;
        vector<int>nums3(n2,-1);
        for(int i=n2-1;i>=0;i--){
            if(st.empty()){
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && st.top()<nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                     st.push(nums2[i]);
                }
                else{
                    nums3[i]=st.top();
                    st.push(nums2[i]);
                }
            }
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n2;i++){
            mp[nums2[i]]=nums3[i];
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=mp[nums1[i]];
        }
        return nums1;
    }

};