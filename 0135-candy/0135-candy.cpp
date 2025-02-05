class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0; // Edge case

        vector<int> lefty(n, 1);  // Initialize to 1
        vector<int> righty(n, 1); // Initialize to 1
        int candi = 0;

        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                lefty[i] = lefty[i - 1] + 1;
            }
        }

        // Right to left pass
        for (int i = n - 2; i >= 0; i--) { // Start from n-2 to avoid out-of-bounds
            if (ratings[i] > ratings[i + 1]) {
                righty[i] = righty[i + 1] + 1;
            }
        }

        // Compute the final result
        for (int i = 0; i < n; i++) {
            candi += max(lefty[i], righty[i]);
        }

        return candi;
    }
};
