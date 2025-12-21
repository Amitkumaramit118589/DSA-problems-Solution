class Solution {
  public:
    vector<int>ans;
    void dfshelp(int u,vector<bool>&vis,vector<vector<int>>&adj){
        ans.push_back(u);
        vis[u]=true;
        for(int v:adj[u]){
            if(!vis[v]){
                dfshelp(v,vis,adj);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<bool>vis(adj.size(),false);
        dfshelp(0,vis,adj);
        return ans;
        
    }
};