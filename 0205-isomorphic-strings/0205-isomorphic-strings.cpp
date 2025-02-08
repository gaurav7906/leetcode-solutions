class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n != m) return false;

        map<char, char> mp, mp2;
        
        for (int i = 0; i < n; i++) {
            char ch = s[i], ch2 = t[i];

            if (mp.count(ch) && mp[ch] != ch2) return false;
            if (mp2.count(ch2) && mp2[ch2] != ch) return false;

            mp[ch] = ch2;
            mp2[ch2] = ch;
        }
        return true;
    }
};
