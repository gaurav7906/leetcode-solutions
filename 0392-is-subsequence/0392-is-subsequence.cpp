class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.length();
        int n=t.length();
        int charcnt=0;
        int j=0;
        for (int i=0;i<n;i++){
            if(t[i]==s[j] && j<m){
                j++;
                charcnt+=1;
            }
        }
        return charcnt==m?true:false;
    }
};