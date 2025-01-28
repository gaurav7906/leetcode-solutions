class Solution {
public:
    int maxDepth(string s)
     {
        int res=0,depth=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                depth++;
                res=max(res,depth);
            }
            else if(s[i]==')')
            {
                depth--;
            }
            else{
                continue;
            }
        }
        return res;
    }
};