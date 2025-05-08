//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int binarysearch(vector<vector<int>>arr,int tar){
        
        int count=0;
        for(int i=0;i<arr.size();i++){
            int st=0;
            int end=arr[0].size()-1;
            while(st<=end){
            int mid=(st+end)/2;
            if(arr[i][mid]<=tar)st=mid+1;
            else end=mid-1;
           }
        count+=st;
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int mi=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(mat[i][0]<mi) mi=mat[i][0];
            if(mat[i][m-1]>maxi) maxi=mat[i][m-1];
        }
        int st=mi;
        int end=maxi;
        while(st<=end){
            int mid=(st+end)/2;
           
            if(binarysearch(mat,mid)<=(n*m)/2) st=mid+1;
            else end=mid-1;
        }
        return st;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends