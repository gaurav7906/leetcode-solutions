class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;
        int ans = 0;
        int count=0;
        
        while (xorResult > 0) {
            count = xorResult & 1; 
            ans+=count;
            xorResult >>=1;
        }   
        return ans;
    }
};