//Approach-1 (Recursion with Memo) : Top Down
class Solution {
public:
    int dp[46];
    int solve(int n){
        if(n == 0 || n == 1 || n == 2)
            return n;
        
        if(dp[n] != -1)
            return dp[n];
        
        int a = solve(n-1);
        int b = solve(n-2);
        
        return dp[n] = a+b;
        
    }
    int climbStairs(int n) {
        for(int i = 0; i < 46; i++){
        dp[i] = -1;
        }
        return solve(n);
        // memset(dp, -1, sizeof(dp));
        // return solve(n);
    }
};



//Approach-2 (Using Bottom Up DP)
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1 || n == 2)
            return n;
        
        vector<int> dp(n+1);
        
        //dp[i] = total ways to climb i stairs
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};