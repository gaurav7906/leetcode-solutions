class Solution {
public:
// bettter solution
    int longestConsecutive(vector<int>& nums) 
    {
    //     int lastsmallest=INT_MIN,countcur=0,longest=1;
    //     int n=nums.size();
    //     if(n==0)
    //     return 0;
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<n;i++)
    //     {
    //         if(nums[i]-1==lastsmallest)
    //         {
    //             lastsmallest=nums[i];
    //             countcur+=1;
    //         }
    //         else if(nums[i]!=lastsmallest)
    //         {
    //             countcur=1;
    //             lastsmallest=nums[i];
    //         }
    //         longest=max(countcur,longest);
    //     }
    //     return longest;
    unordered_set<int>st;
    for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
    }
    int count=0,longest=0;
    for(auto it : st){
        if(st.find(it-1)==st.end()){
            count=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                count+=1;
                x+=1;
            }
            longest=max(longest,count);
        }
    }
    return longest;
    }
};