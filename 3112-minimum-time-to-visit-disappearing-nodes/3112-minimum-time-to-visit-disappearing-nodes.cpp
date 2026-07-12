class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges,
                            vector<int>& disappear) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int len = it[2];
            adj[u].push_back({v, len});
            adj[v].push_back({u, len});
        }

        vector<int> dist(n, 1e9);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int time = it.first;

            if (time > dist[node])
                continue;


            for (auto e : adj[node]) {
                int adjNode = e.first;
                int len = e.second;

                if (time + len >= disappear[adjNode])
                    continue;
                if (time + len < dist[adjNode]) {

                    dist[adjNode] = time + len;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};