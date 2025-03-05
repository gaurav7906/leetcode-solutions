class Solution {
public:
    long long coloredCells(int n) {
        if (n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 5;
        }
        vector<long long >ans(n+1,0);

        ans[0]=0;
        ans[1]=1;
        ans[2]=5;
        int diff;
        for(int i=3;i<n+1;i++){
            ans[i]=ans[i-1]+4*(i-1);
        }
        return ans[n];
    }
};