//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string &s) {
        // code here
         int i=s.length()-1;
        string ans="";
        while(i>=0){
            while(i>=0 && s[i]==' ') i--;
            int j=i;
            while(j>=0 && s[j]!=' '){
                j--;
            }
            
            ans+=s.substr(j+1,i-j);
            i=j;
            ans+=" ";

        }
        while(ans!="" && ans.back()==' ') ans.pop_back();
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;     // Read the number of test cases
    cin.ignore(); // Consume the newline character after reading the integer

    while (t--) {
        string s;
        getline(cin, s); // Read the string input

        string str = s.substr(1, s.size() - 2); // Remove surrounding quotes
        Solution obj;                       // Create an object of the Solution class
        string ans = obj.reverseWords(str); // Reverse the words in the string
        cout << '"';                        // Print opening quote
        cout << ans;                        // Print the result
        cout << '"';                        // Print closing quote
        cout << endl;                       // Print a newline
    }
    return 0; // Return 0 to indicate successful execution
}

// } Driver Code Ends