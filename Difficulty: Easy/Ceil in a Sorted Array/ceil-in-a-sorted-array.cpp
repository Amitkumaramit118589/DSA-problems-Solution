//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int st=0;
        int end=n-1;
        int mid= (st+end)/2;
        int ans=-1;
        while(st<=end){
            mid=(st+end)/2;
            if(arr[mid]>=x){
                end=mid-1;
            }
            else if(arr[mid]<x){
                st=mid+1;
                ans=mid;
            }
            else{
                //return mid;
            }
        }
        if(st+1>n) return -1;
        return st;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string xs;
        getline(cin, xs);
        int x = stoi(xs);
        Solution ob;
        int ans = ob.findCeil(arr, x);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends