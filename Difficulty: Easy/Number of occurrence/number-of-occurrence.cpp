//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n= arr.size();
        int st=0;
        int end=n-1;
        int mid=(st+end)/2;
        int firstidx=-1;
        while(st<=end){
            mid=(st+end)/2;
            if(arr[mid]==target){
                firstidx=mid;
                end=mid-1;
            }
            else if(arr[mid]<target) st=mid+1;
            else end=mid-1;
        }
        if(firstidx==-1)return 0;
        st=0;
        end=n-1;
        int lastidx=-1;
        while(st<=end){
            mid=(st+end)/2;
            if(arr[mid]==target){
                lastidx=mid;
                st=mid+1;
            }
            else if(arr[mid]<target) st=mid+1;
            else end=mid-1;
        }
        return lastidx-firstidx+1;
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
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends