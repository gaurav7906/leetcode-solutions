class Solution {
public:
    bool isValid(string s)
    {
          int n=s.length();
          if(n%2!=0)
            return false;
        stack<char> st;
        for(char c:s)
        {
            if(c=='(' || c=='[' || c=='{')
            st.push(c);
            else
            {
                if(st.empty()|| c==')' && st.top()!='(' ||c==']' && st.top()!='[' ||c=='}' && st.top()!='{' )
                return false;
                 st.pop();
            }
        }
     return st.empty();
    }
};