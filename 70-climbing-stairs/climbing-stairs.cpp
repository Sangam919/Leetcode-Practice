class Solution {
public:
        int dp[46];
        int solve(int n){
            if(n<=2) return n;
             if(dp[n] != -1) return dp[n];

             return dp[n] = solve(n-1) + solve(n-2);
        }
    int climbStairs(int n) {
        for(int i=0;i<46;i++){
            dp[i] = -1;

        }
        return solve(n);
    }
};