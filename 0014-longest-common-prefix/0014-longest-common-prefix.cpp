class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
       string res="";
       int n=strs.size();
       if(n==0){
        return res;
       }
       sort(strs.begin(),strs.end());
       string s1=strs[0];
       if (n==1){
        return s1;
       }
       string s2=strs[n-1];
       for(int i=0; i< min(s1.length(), s2.length()); i++){
        if(s1[i]!=s2[i]){
            return res;
        }
        else{
            res+=s1[i];
        }
       }
       return res;
    }
};