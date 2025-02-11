#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        string temp = ""; 
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            st.push(s[i]);
            temp.push_back(s[i]);
            if (st.size() >= part.length()) {
                string subs = temp.substr(temp.length() - part.length());
                if (subs == part) {
                    for (int j = 0; j < part.length(); j++) {
                        st.pop();
                    }
                    temp.erase(temp.length() - part.length());
                }
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
