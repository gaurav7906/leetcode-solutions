class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int count=0;
        int n=colors.size();
        int maxtime=neededTime[0];
        for(int i=1;i<n;i++){
            
            if(colors[i]==colors[i-1]){
                count+=min(maxtime,neededTime[i]);
                maxtime=max(neededTime[i],maxtime);
            }
            else{
                maxtime=neededTime[i];
            }
        }
        return count;
    }
};

