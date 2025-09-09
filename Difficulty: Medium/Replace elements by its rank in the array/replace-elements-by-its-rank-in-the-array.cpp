// User function Template for C++
class cmp{
    public:
    bool operator()(pair<int,int>a,pair<int,int>b){
        return a.first>b.first;
    }
};

class Solution {
  public:
   
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<N;i++){
            pq.push({arr[i],i});
        }
        
        int rank=1;
        pair<int,int>curr;
        vector<int>ans(N);
        int prev=-1;
        while(pq.size()>0){
            curr=pq.top();
            pq.pop();
            if(curr.first!=prev){
                ans[curr.second]=rank;
                rank++;
            }
            else{
                ans[curr.second]=rank-1;
            }
            prev=curr.first;
            
            
        }
        return ans;
    }
};
