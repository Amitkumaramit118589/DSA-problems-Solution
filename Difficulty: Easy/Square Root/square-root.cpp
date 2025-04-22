//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        if(n==1 ||n== 0) return 1;
        int st=1;
        int end=n/2;
        int mid=(st+end)/2;
        int ans=1;
        
        while(st<=end){
            mid=(st+end)/2;
            long long square = 1LL * mid * mid;

            if(square==n) return mid;
            else if(square>n){
              end=mid-1;
            } 
            else{
                 st=mid+1;
                 ans=mid;
            } 
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends