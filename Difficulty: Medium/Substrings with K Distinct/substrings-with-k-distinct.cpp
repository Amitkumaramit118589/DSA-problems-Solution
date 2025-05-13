//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here.
        int n=s.size();
        int res=0;
        for(int i=0;i<n;i++){
            vector<int>cnt(26,0);
            int distcnt=0;
            for(int j=i;j<n;j++){
                if(cnt[s[j]-'a']==0){
                    distcnt++;
                    cnt[s[j]-'a']++;
                }
                if(distcnt==k){
                    res++;
                }
                else if (distcnt > k) break;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends