// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
        int ans=0;
        while(k-- && pq.size()>0){
            ans=pq.top();
            pq.pop();
            
        }
        return ans;
    }
};