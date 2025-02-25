class Solution {
public:
    string getsub(string &s){
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='+'){
                break;
            }
           else if(s[i]=='.'){
                continue;
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int>mp;
        int count=0;
        int n=emails.size();
        for(int i=0;i<n;i++){
            int pos=emails[i].find('@');
            string extract=emails[i].substr(0,pos);
            string temp1=getsub(extract);
            string temp2=emails[i].substr(pos);
            string temp=temp1+temp2;
            if(mp.find(temp)==mp.end()){
                count+=1;
                mp[temp]=1;
            }
            else{
                mp[temp]+=1;
            }
        }
        return count;
    }
};