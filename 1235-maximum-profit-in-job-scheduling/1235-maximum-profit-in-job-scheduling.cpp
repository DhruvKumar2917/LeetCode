class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        vector<vector<int>> job;

        for (int i = 0; i < n; i++) {
            int start = startTime[i];
            int end = endTime[i];
            int pro = profit[i];

            job.push_back({start, end, pro});
        }

        sort(job.begin(), job.end());

        vector<int> dp(n + 1, 0);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {

            int next = lower_bound(job.begin() + i + 1, job.end(),
                                   vector<int>{job[i][1], 0, 0}) -
                       job.begin();
            int take = job[i][2] + dp[next];

            int notTake = dp[i + 1];

            dp[i] = max(take, notTake);
        }

        return dp[0];
    }
};