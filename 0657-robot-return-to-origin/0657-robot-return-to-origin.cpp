class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.length();
        int l=0;
        int u=0;
        for(int i=0;i<n;i++){
            if (moves[i] == 'L'){
                ++l;
            } else if (moves[i] == 'R'){
                --l;
            } else if (moves[i] == 'U'){
                ++u;
            } else {
                --u;
            }
        }
        if (l==0 && u ==0){
            return true;
        }
        return false;
    }
};