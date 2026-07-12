class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {

        vector<vector<array<int,3>>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2], e[3]});
        }

        const long long INF = 1e18;
        vector<long long> dist(n, INF);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        pq.push({0,0});

        while (!pq.empty()) {

            auto [time, node] = pq.top();
            pq.pop();

            if (time != dist[node])
                continue;

            if (node == n - 1)
                return time;

            for (auto &e : adj[node]) {

                int nxt = e[0];
                long long start = e[1];
                long long end = e[2];

                // Can't use this edge anymore.
                if (time > end)
                    continue;

                // Wait until the edge opens if necessary.
                long long depart = max(time, start);
                long long arrival = depart + 1;

                if (arrival < dist[nxt]) {
                    dist[nxt] = arrival;
                    pq.push({arrival, nxt});
                }
            }
        }

        return -1;
    }
};