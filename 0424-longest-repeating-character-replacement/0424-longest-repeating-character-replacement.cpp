class Solution {
public:
    int characterReplacement(string s, int k) {
       int n=s.length();
       int l=0,r=0;
       unordered_map<char,int>mp;
       int maxf=0;
       int maxlen=0;
       while(r<n){
        mp[s[r]]+=1;
        maxf=max(maxf,mp[s[r]]);
        while(r-l+1-maxf>k){
            mp[s[l]]--;
            for(auto it:mp){
                int frq=it.second;
                maxf=max(maxf,frq);
            }
            l+=1;
        }
        if(r-l+1-maxf<=k){
            maxlen=max(maxlen,r-l+1);
             r+=1;
        }
       
       }
       return maxlen;
    }
};


