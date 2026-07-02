class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m,vector<int>(n,1e9));

        pq.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};



        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int health = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x == m-1 && y == n-1) break;

            for(int k =0;k<4;k++){
                int nrow = x + dr[k];
                int ncol = y + dc[k];
                if(nrow>= 0 && nrow<m && ncol>=0 && ncol<n && health + grid[nrow][ncol] < dist[nrow][ncol]){
                    dist[nrow][ncol] = health + grid[nrow][ncol];
                    pq.push({dist[nrow][ncol],{nrow,ncol}});
                }
            }

            
        }
        if(dist[m-1][n-1] < health ) return true;
        else return false;
        
    }
};