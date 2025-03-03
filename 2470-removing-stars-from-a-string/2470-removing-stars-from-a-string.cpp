class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        string ans="";
        if(st.size()==0){
            return "";
        }
        else{
            while(!st.empty()){
                int ch=st.top();
                st.pop();
                ans.push_back(ch);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};