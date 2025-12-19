class Solution {
  public:
    vector<vector<int>> adj;
        void dfs(int i,vector<bool> &vis,vector<int> &temp){
            vis[i]=true;
            temp.push_back(i);
            for(int j:adj[i]){
                if(!vis[j]){
                    dfs(j,vis,temp);
                }
            }
        }
         
     
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
         adj.resize(V);
         for(auto& it:edges){
             int u=it[0];
             int v=it[1];
             adj[u].push_back(v);
             adj[v].push_back(u);
         }
         vector<bool> vis(V,false);
         vector<vector<int>> res;
         for(int i=0;i<V;i++){
             if(!vis[i]){
                 vector<int> temp;
                 dfs(i,vis,temp);
                 res.push_back(temp);
             }
         }
         return res;
        
    }
};