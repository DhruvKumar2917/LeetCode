class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n,vector<int>(n,1e9));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq;

        pq.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];

        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(dist[row][col] < time) continue;

            if(row == n- 1 && col == n-1) return dist[row][col];

            for(int i = 0; i < 4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow >= 0 && ncol >=0 && nrow < n && ncol < n){
                    int depart = max(grid[nrow][ncol],time);

                    if(depart < dist[nrow][ncol]){
                        dist[nrow][ncol] = depart;
                        pq.push({depart,{nrow,ncol}});
                    }


                }
            }


        }
        return dist[n-1][n-1];
        
    }
};