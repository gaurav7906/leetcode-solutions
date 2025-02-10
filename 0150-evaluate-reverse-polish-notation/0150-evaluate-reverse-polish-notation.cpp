class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int>st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            string as=tokens[i];
            if(as!="+" && as!="-" && as!="*" && as!="/"){
                int num=stoi(as);
                st.push(num);
            }
            else if(as=="+"){
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                st.push(num1+num2);
            }
             else if(as=="-"){
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                st.push(-num1+num2);
            }
            else if(as=="*"){
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                st.push(num1*num2);
            }
            else {
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                st.push(num2/num1);
            }
        }
        return st.top();
    }
};