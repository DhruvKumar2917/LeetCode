class Solution {

    bool check(int score, vector<vector<pair<int, int>>>& adj, long long k,
               int n) {

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        vector<long long> dist(n, 1e18);

        dist[0] = 0;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            long long wt = it.first;
            int node = it.second;

           
            if (wt > k)
                return false;

            if (node == n - 1)
                return true;

            if (dist[node] < wt)
                continue;

            for (auto nei : adj[node]) {
                int adjNode = nei.first;
                int cost = nei.second;

                if (cost < score)
                    continue;

                if (dist[adjNode] > cost + wt) {
                    dist[adjNode] = cost + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return false;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);
        int l = INT_MAX;
        int r = 0;

        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            int cost = e[2];

            if (!online[u] || !online[v])
                continue;
            adj[u].push_back({v, cost});

            l = min(l, cost);
            r = max(r, cost);
        }

        int ans = -1;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (check(mid, adj, k, n)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};