class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {

        vector<vector<pair<int,int>>> startAt(n);

        for (auto &offer : offers) {
            int s = offer[0];
            int e = offer[1];
            int gold = offer[2];

            startAt[s].push_back({e, gold});
        }

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            // Skip this house
            dp[i] = dp[i + 1];

            // Take any offer starting here
            for (auto &it : startAt[i]) {
                int end = it.first;
                int gold = it.second;

                dp[i] = max(dp[i], gold + dp[end + 1]);
            }
        }

        return dp[0];
    }
};