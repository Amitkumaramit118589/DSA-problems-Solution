//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   long long fn(int n, int mid) {
    long long mult = 1;
    for(int i = 0; i < n; i++) {
        mult *= mid;
        if (mult > 1e18) return mult; // to prevent overflow
    }
    return mult;
}

    int nthRoot(int n, int m) {
        int low = 1, high = m;
        
        while(low <= high){
            int mid = (low + high) / 2;
            long long power = fn(n, mid);
            
            if(power == m) return mid;
            else if(power < m) low = mid + 1;
            else high = mid - 1;
        }
        
        return -1; // If no integer root exists
    }

};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends