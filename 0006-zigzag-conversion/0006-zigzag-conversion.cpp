class Solution {
public:
    string convert(string s, int numRows)
     {
         int i=0;
        vector<string> ans(numRows);
        if(numRows==1)
        {
            return s;
        }
        bool flag=false;
        for(auto ch : s)
        {
            ans[i]+=ch;
            if(i==0 || i==numRows-1)
            {
                flag=!flag;
            }
            if(flag)
            {
                i+=1;
            }
            else
            i-=1;
        }
        string zig="";
        for(auto str: ans)
        {
            zig +=str;
        }
        return zig;
    }
};