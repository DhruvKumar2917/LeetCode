class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        vector<pair<int,int>> vec;

        for(int i = 0; i < n; i++){
            vec.push_back({arr[i], i});
        }

        sort(vec.begin(), vec.end());

        vector<int> dp(n, 1);

        int ans = 1;

        for(int i = 0; i < n; i++){

            int ind = vec[i].second;

            // Check left
            for(int j = ind - 1; j >= max(0, ind - d); j--){

                if(arr[j] >= arr[ind]) break;

                dp[ind] = max(dp[ind], 1 + dp[j]);
            }

            // Check right
            for(int j = ind + 1; j <= min(n - 1, ind + d); j++){

                if(arr[j] >= arr[ind]) break;

                dp[ind] = max(dp[ind], 1 + dp[j]);
            }

            ans = max(ans, dp[ind]);
        }

        return ans;
    }
};