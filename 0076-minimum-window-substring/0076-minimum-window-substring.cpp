class Solution {
public:
    string minWindow(string s, string t) {
    int n=s.length();
    int m=t.length();
    if(m>n){
        return "";
    }
    int startingindex=-1;
    int count=0;
    map<char,int>mp;
    for(int i=0;i<m;i++){
        mp[t[i]]++;
    }
    int r=0,l=0,minlen=INT_MAX;
    while(r<n){
        if(mp[s[r]]>0){
            count+=1;
        }
        mp[s[r]]--;
        while(count==m){
            if(minlen>r-l+1){
                minlen=r-l+1;
                startingindex=l;
            }
            mp[s[l]]++;
            if(mp[s[l]]>0){
                count-=1;
            }
            l++;
        }
        r++;
    }
     return (startingindex == -1) ? "" : s.substr(startingindex, minlen);
    }
};