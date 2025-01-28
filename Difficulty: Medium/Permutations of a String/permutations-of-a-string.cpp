//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   void permu(vector<string>& res, string &s, int index) {
    if (index == s.length()) {
        res.push_back(s);
        return;
    }
    unordered_set<char> used;  // Keep track of characters used at this level
    for (int i = index; i < s.length(); i++) {
        if (used.find(s[i]) != used.end()) {
            continue;  // Skip duplicate characters
        }
        used.insert(s[i]);
        swap(s[index], s[i]);  // Swap characters
        permu(res, s, index + 1);  // Recurse
        swap(s[index], s[i]);  // Backtrack
    }
}

vector<string> findPermutation(string &s) {
    vector<string> res;
    sort(s.begin(), s.end());  // Sort the string to ensure duplicates are handled
    permu(res, s, 0);
    return res;
}

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends