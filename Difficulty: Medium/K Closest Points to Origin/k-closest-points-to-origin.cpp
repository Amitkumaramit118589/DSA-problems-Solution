//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        // Your code here
        vector<vector<int>>ans;
        priority_queue<pair<double,pair<int,int>>>pq;
        for(int i=0;i<p.size();i++){
            if(i<k){
                double dis = sqrt(p[i][0]*p[i][0] + p[i][1]*p[i][1]);
                pq.push({dis,{p[i][0],p[i][1]}});
            }
            else{
                double dis = sqrt(p[i][0]*p[i][0] + p[i][1]*p[i][1]);
                pq.push({dis,{p[i][0],p[i][1]}});
                pq.pop();
            }
        }
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            vector<int>v;
            v.push_back(x.second.first);
            v.push_back(x.second.second);
            ans.push_back(v);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends