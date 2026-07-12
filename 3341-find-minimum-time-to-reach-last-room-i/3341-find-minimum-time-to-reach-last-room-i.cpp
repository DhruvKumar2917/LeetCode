class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {

        int n = moveTime.size();
        int m = moveTime[0].size();

        const long long INF = 1e18;

        vector<vector<long long>> dist(n, vector<long long>(m, INF));

        priority_queue<
            pair<long long, pair<int, int>>,
            vector<pair<long long, pair<int, int>>>,
            greater<pair<long long, pair<int, int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto [time, cell] = pq.top();
            pq.pop();

            int row = cell.first;
            int col = cell.second;

            // Ignore stale entries
            if (time > dist[row][col])
                continue;

            // Reached destination
            if (row == n - 1 && col == m - 1)
                return (int)time;

            for (int i = 0; i < 4; i++) {

                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                    continue;

                long long depart = max(time, 1LL * moveTime[nrow][ncol]);
                long long arrival = depart + 1;

                if (arrival < dist[nrow][ncol]) {
                    dist[nrow][ncol] = arrival;
                    pq.push({arrival, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};