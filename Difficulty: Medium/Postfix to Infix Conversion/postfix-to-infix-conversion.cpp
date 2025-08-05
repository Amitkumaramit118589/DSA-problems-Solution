// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string>st;
        for(int i=0;i<exp.size();i++){
            if((exp[i]>='a'&& exp[i]<='z') || (exp[i]>='A'&& exp[i]<='Z')) {
                st.push(string(1,exp[i]));
            }
            else{
               string op1=st.top();
                st.pop();
               string op2=st.top();
                st.pop();
                
                st.push('('+op2+exp[i]+op1+')');
            }
        }
        return st.top();
    }
};