class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
         int maxi=-1;
        for(int i=0;i<candies.size();i++){
            if(candies[i]>maxi){
                maxi=candies[i];
            }
        }
        vector<bool>ans(candies.size(),true);
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maxi){
                ans[i]=true;
            }
            else{
                ans[i]=false;
            }
        }
        return ans;
    }
};