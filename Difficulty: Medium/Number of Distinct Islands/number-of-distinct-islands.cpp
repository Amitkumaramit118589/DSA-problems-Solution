// User function Template for C++

class Solution {
    private:
    void BFS(set<vector<pair<int, int>>> &st, int i, int j, vector<vector<int>> &grid){
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        vector<pair<int, int>> vec;
        grid[i][j]= 0;
        int realRow= i;
        int realCol= j;
        while(!q.empty()){
            auto front= q.front();
            q.pop();
            int row= front.first;
            int col= front.second;
            vec.push_back(make_pair(row-realRow, col-realCol));
            //chec for the fourdirectionn
            //right
            if(col+1<grid[row].size() and grid[row][col+1]==1){
                q.push(make_pair(row, col+1));
                grid[row][col+1]=0;
                
            }
            //left;
            if(col-1>=0 and grid[row][col-1]==1){
                q.push(make_pair(row, col-1));
                grid[row][col-1]=0;
            }
            //up;
            if(row-1>=0 and grid[row-1][col]==1)
            {
                q.push(make_pair(row-1, col));
                grid[row-1][col]=0;
            }
            //down
            if(row+1<grid.size() and grid[row+1][col]==1){
                q.push(make_pair(row+1, col));
                grid[row+1][col]=0;
            }
        }
        st.insert(vec);
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        // unordered_set<vector<pair<int, int>>> st;
        set<vector<pair<int, int>>> st;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1){
                    // vector<pair<int, int>> vec;
                    BFS(st, i, j, grid);
                    
                
                }
            }
        }
        return st.size();
    }
};