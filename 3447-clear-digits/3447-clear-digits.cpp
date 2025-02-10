class Solution {
public:
    string clearDigits(string s) {
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                if(temp.length()>0){
                    temp.pop_back();
                }
                else{
                    continue;
                }
            }
            else{
                temp.push_back(s[i]);
            }
        }
        return temp;
    }
};