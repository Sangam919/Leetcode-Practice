class Solution {
public:
    int helper(int i, int j, int k, int neu, vector<vector<int>> &coins, vector<vector<vector<int>>> &dp){
        if(i == 0 && j == 0 ){
            if(coins[i][j] >= 0){
                return coins[i][j];
            }
            else if(k < neu){
                return 0;
            }
            else{
                return coins[i][j];
            }
        }

        if(dp[i][j][k] != INT_MIN){
            return dp[i][j][k];
        }

        int left = INT_MIN;
        if(j-1 >= 0){
            if(coins[i][j] >= 0){
                left = max(left, coins[i][j] + helper(i, j-1, k, neu, coins, dp));
            }
            else{
                left = max(left, coins[i][j] + helper(i, j-1, k, neu, coins, dp));
                if(k < neu){
                    left = max(left, helper(i, j-1, k+1, neu, coins, dp));
                }
            }
            
        }
        
        int up = INT_MIN;
        if(i-1 >= 0){
            if(coins[i][j] >= 0){
                up = max(up, coins[i][j] + helper(i-1, j, k, neu, coins, dp));
            }
            else{
                up = max(up, coins[i][j] + helper(i-1, j, k, neu, coins, dp));
                if(k < neu){
                    up = max(up, helper(i-1, j, k+1, neu, coins, dp));
                }
            }
        }

        return dp[i][j][k] = max(left, up);
    }


public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        return helper(m-1, n-1, 0, 2, coins, dp);
    }
};