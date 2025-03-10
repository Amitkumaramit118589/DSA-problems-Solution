//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
   int m , n;
    int dp[1001][1001];
    int solve(int i,int j,string &s,string &t) {
        if(i >= m)
           return n-j;
        if(j >= n)
           return m-i;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int opt = INT_MAX;
        
        if(s[i]==t[j]) {
            return dp[i][j] = solve(i+1,j+1,s,t);
        }   
        else{
            int op1 = 1 + solve(i,j+1,s,t);
            int op2 = 1 + solve(i+1,j,s,t);
            int op3 = 1 + solve(i+1,j+1,s,t);
            
            
            opt = min(opt,min(op1,min(op2,op3)));
        }
        
        return dp[i][j] =  opt;
    }
    int editDistance(string& s1, string& s2) {
        m = s1.size();
        n = s2.size();
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0,0,s1,s2);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends