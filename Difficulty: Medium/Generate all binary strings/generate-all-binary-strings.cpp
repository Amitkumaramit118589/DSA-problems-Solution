//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends