#include <vector>
#include <algorithm>

class Solution {
public:
    int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n, 0);
        for (int i = 0; i < n; i++) {
            time[i] = (dist[i] + speed[i] - 1) / speed[i];  
        }

        sort(time.begin(), time.end());  

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (time[i] <= i) { 
                break;
            }
            count++;
        }

        return count;
    }
};
