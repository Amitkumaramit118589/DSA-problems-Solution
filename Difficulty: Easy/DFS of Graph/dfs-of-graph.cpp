class Solution {
  public:
    
    void helper(int u,vector<int> &ans,vector<bool>&vis,vector<vector<int>>&adj){
        ans.push_back(u);
        vis[u]=true;
        for(int i:adj[u]){
            if(!vis[i]){
                helper(i,ans,vis,adj);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        vector<bool>vis(adj.size(),false);
        int src=0;
        helper(src,ans,vis,adj);
        return ans;
    }
};