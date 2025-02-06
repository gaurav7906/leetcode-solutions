class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end()); 

        string temp = "", ans = "";
        int n = s.length();
        int i = 0;

        while (i < n) {
            if (s[i] != ' ') {  
                temp += s[i];  
            } 
            else if (!temp.empty()) { 
                reverse(temp.begin(), temp.end()); 
                if (!ans.empty()) ans += " "; 
                ans += temp;  
                temp = "";  
            }
            i++;
        }

        
        if (!temp.empty()) {
            reverse(temp.begin(), temp.end());
            if (!ans.empty()) ans += " ";
            ans += temp;
        }

        return ans;
    }
};
