// User function Template for C++

class Solution {
  public:
  bool isoperator(char ch){
        if( ch=='*' || ch=='^' || ch=='/' || ch=='+' || ch=='-'  ) return true;
        else return false;
        
    }
    string preToPost(string pre_exp) {
         stack<string>st;
        int n=pre_exp.size();
        for(int i=n;i>=0;i--){
            if(isoperator(pre_exp[i])){
                string op1=st.top();
                st.pop();
                string op2=st.top();
                st.pop();
                
                st.push(op1+op2+pre_exp[i]);
            }
            else{
                st.push(string(1, pre_exp[i]));
            }
        }
        return st.top();
    }
};