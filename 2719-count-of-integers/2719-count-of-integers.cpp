class Solution {

    const int mod = 1e9 + 7;

    long dp[23][2][401];

public:


    long f(int index, bool tight, int sum , int &min_sum, int &max_sum, string &s){
        if(index == s.size()){
            return sum >= min_sum and sum <= max_sum;
        }


        if(dp[index][tight][sum]!=-1){
            return dp[index][tight][sum];

        }

        long ans = 0;
        int limit = tight? s[index] - '0':9;

        for(int d=0;d<=limit;d++){
            int newTight = tight & (d==limit);
            ans += (f(index+1,newTight,sum + d, min_sum,max_sum,s)%mod);
        }

        return dp[index][tight][sum] = ans;


    }

    int count(string num1, string num2, int min_sum, int max_sum) {

        memset(dp,-1,sizeof(dp));

        long countNum1 = f(0,true,0,min_sum,max_sum,num1);

        memset(dp,-1,sizeof(dp));
        long countNum2 = f(0,true,0,min_sum,max_sum,num2);


        int sum = 0;

        for(auto d : num1)
            sum += (d-'0');

        if(sum>=min_sum && sum<=max_sum) countNum1--;

        return (((countNum2 - countNum1)%mod) + mod)%mod;    
        }
        


       

        
    
};