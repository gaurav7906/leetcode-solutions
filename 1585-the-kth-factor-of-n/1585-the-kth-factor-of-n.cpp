class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>ans;
        ans.push_back(1);
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                ans.push_back(n/i);
            }
        }
        int m=ans.size();
        if(m<k)
        return -1;
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};