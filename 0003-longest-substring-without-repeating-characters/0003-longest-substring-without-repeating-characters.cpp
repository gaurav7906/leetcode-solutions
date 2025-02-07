#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxi = 0;  // Maximum length of substring without repetition
        int j = 0;  // Left pointer of the window
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (mp.find(ch) != mp.end() && mp[ch] >= j) {
                j = mp[ch] + 1;  
            }
            mp[ch] = i;
            maxi = max(maxi, i - j + 1);
        }
        return maxi;
    }
};
