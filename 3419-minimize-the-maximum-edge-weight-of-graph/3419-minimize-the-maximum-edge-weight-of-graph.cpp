class Solution {
public:

    bool check(int n, vector<vector<int>>& edges, int limit) {

        vector<vector<int>> rev(n);

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (w <= limit) {
                rev[v].push_back(u);
            }
        }

        vector<int> vis(n, 0);

        queue<int> q;
        q.push(0);

        vis[0] = 1;

        int cnt = 1;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int nei : rev[node]) {

                if (!vis[nei]) {

                    vis[nei] = 1;
                    cnt++;
                    q.push(nei);
                }
            }
        }

        return cnt == n;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {

        if (threshold == 0) {
            return (n == 1 ? 0 : -1);
        }

        int low = 1;
        int high = 0;

        for (auto &e : edges) {
            high = max(high, e[2]);
        }

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(n, edges, mid)) {

                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};