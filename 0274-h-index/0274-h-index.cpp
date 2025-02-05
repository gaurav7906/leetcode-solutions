class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.rbegin(), citations.rend()); // Sort in descending order

        int hIndex = 0;
        for (int i = 0; i < n; i++) {
            if (citations[i] >= i + 1) { 
                hIndex = i + 1;  // Update h-index
            } else {
                break;  // Once we find a citation that does not meet the condition, we stop
            }
        }
        return hIndex;
    }
};
