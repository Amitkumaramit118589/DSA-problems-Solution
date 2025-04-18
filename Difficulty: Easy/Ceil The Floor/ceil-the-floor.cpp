//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        
        int ans1=-1;
        int ans2=INT_MAX;
        int n=arr.size();
        int flag1=0;
        int flag2=0;
        vector<int>ans(2,-1);
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                ans1=x;
                ans2=x;
                flag1=1;
                flag2=1;
            }
            else if(arr[i]<x){
                ans1= max(ans1,arr[i]);
                flag1=1;
            }
            else{
                ans2=min(ans2,arr[i]);
                flag2=1;
            }
        }
        ans[0]=ans1;
        ans[1]=ans2;
        if(flag2==0) ans[1]=-1;
        if(flag1==0) ans[0]=-1;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends