//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     bool isPossible(vector<int>& stations, double dist, int k) {
        int count = 0;
        for(int i = 1; i < stations.size(); i++) {
            double gap = stations[i] - stations[i - 1];
            count += int(gap / dist); // floor(gap / dist)
        }
        return count <= k;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
         double lo = 0, hi = 0;

        for(int i = 1; i < stations.size(); i++) {
            hi = max(hi, double(stations[i] - stations[i - 1]));
        }

        while(hi - lo > 1e-6) {
            double mid = (lo + hi) / 2.0;
            if(isPossible(stations, mid, k)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return round(hi * 100.0) / 100.0; // round to 2 decimal places
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends