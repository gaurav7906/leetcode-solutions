class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> sting;
        string temp = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                sting.push_back(temp);
                temp = "";
            } else {
                temp += s[i];
            }
        }
        sting.push_back(temp);

        if (pattern.length() != sting.size()) return false;

        map<char, string> mp;
        map<string, char> mp2;

        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern[i];
            string word = sting[i];

            if (mp.count(ch) && mp[ch] != word) return false;
            if (mp2.count(word) && mp2[word] != ch) return false;

            mp[ch] = word;
            mp2[word] = ch;
        }
        return true;
    }
};
