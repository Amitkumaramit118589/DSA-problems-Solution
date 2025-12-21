class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int>ans;
        vector<bool>vis(adj.size(),false);
        queue<int>q;
        
        q.push(0);
        vis[0]=true;
        while(q.size()>0){
            int f=q.front();
            ans.push_back(f);
            q.pop();
            for(int v:adj[f]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
        return ans;
    }
};