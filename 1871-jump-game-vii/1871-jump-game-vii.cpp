class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
       int n = s.length();

        // vector<int> dp(n, 0);
        // dp[n - 1] = s[n-1] == '0'? 1:0 ;

        // for (int i = n - 2; i >= 0; i--) {

        //     if (s[i] == '1')
        //         continue;

        //     for (int j = i + minJump; j <= min(n - 1, i + maxJump); j++) {

        //         if (dp[j]) {
        //             dp[i] = 1;
        //             break;
        //         }
        //     }
        // }

        // return dp[0];

        vector<int> dp(n,0);

        dp[0] = 1;
         long  count = 0;

        for(int i =1;i<n;i++){
           
            if(i-minJump>=0){
                count += dp[i-minJump];

            }
            if(i-maxJump-1>=0){
                count -= dp[i-maxJump-1];
            }

            if(count > 0 && s[i]=='0'){
                dp[i] = 1;
            }
        }

        return dp[n-1]>0;

    
    }
};