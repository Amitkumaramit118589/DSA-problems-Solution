//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int st=0;
        int end=n-1;
        int mid=(st+end)/2;
        int ans=n;
        while(st<=end){
            mid=(st+end)/2;
            if(arr[mid]>target){
                end=mid-1;
                ans=mid;
            }
            else if(arr[mid]<=target){
                st=mid+1;
                ans=st;
            }
            else{
                return mid;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.upperBound(arr, d);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends