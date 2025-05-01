//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  int help(vector<int>arr,int sum){
      int tsum=0;
      int count=1;
      for(int i=0;i<arr.size();i++){
          if(sum>=tsum+arr[i]) tsum+=arr[i];
          else{
              count++;
              tsum=arr[i];
          }
      }
      return count;
  }
    int minTime(vector<int>& arr, int k) {
        // code here
        int maxm=*max_element(arr.begin(),arr.end());
        int sum=accumulate(arr.begin(),arr.end(),0);
        int st=maxm;
        int end=sum;
        int mid=(st+end)/2;
        while(st<=end){
            mid=(st+end)/2;
            if(help(arr,mid)<=k) end=mid-1;
            else st=mid+1;
        }
        return st;
        // return minimum time
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends