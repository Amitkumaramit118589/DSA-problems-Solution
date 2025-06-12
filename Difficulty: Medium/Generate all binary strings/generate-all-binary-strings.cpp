//User function Template for C++

class Solution{
public:
    void help(vector<string>&s,string temp,int num){
        if(num==0){
            s.push_back(temp);
            return;
        }
        help(s,temp+"0",num-1);
       if(temp=="" || temp[temp.length()-1]=='0') help(s,temp+"1",num-1);
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string> s;
        help(s,"",num);
        return s;
    }
};
