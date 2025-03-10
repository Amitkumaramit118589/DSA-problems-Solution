//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        int on1=a;
        int on2=b;
        while(a%b!=0){
            int rem=a%b;
            a=b;
            b=rem;
        }
        vector<int>ans;
        int gcd=b;
        int lcm=(on1*on2)/gcd;
        ans.push_back(lcm);
        ans.push_back(gcd);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends