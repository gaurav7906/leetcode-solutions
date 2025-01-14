class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return minOperations(n1 - 1, n2 - 1, word1, word2, dp);
    }

    int minOperations(int index1, int index2, string &word1, string &word2, vector<vector<int>> &dp) {
        if (index1 < 0) return index2 + 1; // If word1 is exhausted, insert the remaining characters of word2
        if (index2 < 0) return index1 + 1; // If word2 is exhausted, delete the remaining characters of word1

        if (dp[index1][index2] != -1)
         return dp[index1][index2];

        if (word1[index1] == word2[index2]) {
            dp[index1][index2] = minOperations(index1 - 1, index2 - 1, word1, word2, dp);
        } else {
            int deleteFromWord1 = minOperations(index1 - 1, index2, word1, word2, dp) + 1;
            int insertIntoWord1 = minOperations(index1, index2 - 1, word1, word2, dp) + 1;
            int replaceInWord1 = minOperations(index1 - 1, index2 - 1, word1, word2, dp) + 1;

            dp[index1][index2] = min({deleteFromWord1, insertIntoWord1, replaceInWord1});
        }

        return dp[index1][index2];
    }
};
