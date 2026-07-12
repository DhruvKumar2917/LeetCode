class Solution {

    bool dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>> &vis,unordered_map<int,vector<vector<int>>> &directions,int m,int n ){

        if(row == m-1 && col == n-1) return true;

        vis[row][col] = 1;

        for(auto it: directions[grid[row][col]]){
            int nrow = row + it[0];
            int ncol = col + it[1];

            if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0 && !vis[nrow][ncol]){
                for(auto back: directions[grid[nrow][ncol]]){
                    if(nrow + back[0] == row && ncol + back[1] == col){
                        if(dfs(nrow,ncol,grid,vis,directions,m,n)) return true;
                    }
                }
            }
        }
        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<int,vector<vector<int>>> directions = {
            {1,{{0,-1},{0,1}}},
            {2,{{-1,0},{1,0}}},
            {3,{{0,-1},{1,0}}},
            {4,{{0,1},{1,0}}},
            {5,{{-1,0},{0,-1}}},
            {6,{{-1,0},{0,1}}}
        };
        vector<vector<int>> vis(m,vector<int>(n,0));

        return dfs(0,0,grid,vis,directions,m,n);
        
    }
};