class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0, right = 0, countw = 0;
        int mini = INT_MAX;
        int n = blocks.length();
        while (right < n) {
            if (blocks[right] == 'W') {
                countw++;
            }
            if (right - left + 1 == k) {
                mini = min(mini, countw);
                if (blocks[left] == 'W') {
                    countw--;
                }
                left++;
            }        
            right++;
        }     
        return mini;
    }
};
