class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int i=0, j=0;
        int n = s.length()-1;
        while(j<s.length()){
            if(s[j]==s[i]){
                if(j-i+1 == k)
                {
                    if(i==0){
                        if(j == n){
                            return 1;
                        }
                        else if(j < n && s[j]!=s[j+1]){
                            return 1;
                        }
                    }
                    else if(i > 0 && s[i-1]!=s[i]){
                        
                        if(j == n){
                            return 1;
                        }
                        else if(j < n && s[j]!=s[j+1]){
                            return 1;
                        }
                    }
                    j++;
                    i=j;
                }
                else
                {
                    j++;
                }
            }else{
                i=j;
                j=i+1;
            }
        }
        return 0;
    }
};