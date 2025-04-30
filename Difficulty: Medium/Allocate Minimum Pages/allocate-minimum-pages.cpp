//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countstd(vector<int>& arr, int mid) {
        int st_cnt = 1;
        int cntsum = 0;
        for(int i = 0; i < arr.size(); i++) {
            if (arr[i] > mid) return INT_MAX; // Single book too large
            if (cntsum + arr[i] <= mid) {
                cntsum += arr[i];
            } else {
                st_cnt++;
                cntsum = arr[i];
            }
        }
        return st_cnt;
    }

    int findPages(vector<int>& arr, int k) {
        if (arr.size() < k) return -1;  // Not enough books
        
        int st = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);
        int res = -1;

        while (st <= end) {
            int mid = (st + end) / 2;
            int std = countstd(arr, mid);
            if (std <= k) {
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return res;
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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends