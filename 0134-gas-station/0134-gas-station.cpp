class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),totaldiff=0,fuel=0,index=0,diff;
        for(int i =0;i<n;i++){
            diff=gas[i]-cost[i];
            totaldiff+=diff;
            fuel+=diff;
            if(fuel<0){
                index=i+1;
                fuel=0;
            }
        }
        if(totaldiff<0){
            return -1;
        }
        return index;
    }
};