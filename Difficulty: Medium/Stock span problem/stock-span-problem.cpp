//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
         int n = arr.size();
        vector<int> ans(n);
        
        // stack 
        stack<int> st;
        st.push(0);
        ans[0]=1;
        
        for(int i=1; i<n; i++){
            while(!st.empty() && arr[i] >= arr[st.top()]) st.pop();
            if(st.empty()) ans[i] = i+1;
            else ans[i] = i - st.top();
            st.push(i);
        }   
        
        return ans;
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
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends