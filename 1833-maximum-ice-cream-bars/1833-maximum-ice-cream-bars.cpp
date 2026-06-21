class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort (costs.begin(),costs.end());
        int tot_bars =0;
        int rem     = coins;
        for (int i=0;i<costs.size();i++) {

             rem = rem-costs[i];

             if (rem<0)
             return tot_bars;
             tot_bars++;

        }
        return tot_bars;
    }
};