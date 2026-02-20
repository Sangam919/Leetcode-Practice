class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++){
            for(int coin : coins){
                if(i >= coin){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        if(dp[amount] > amount) return -1;
        return dp[amount];
    }
};










// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amt) {
//         if(amt<1) return 0;
//         vector<int> dp(amt+1, INT_MAX);
//         dp[0] =0;
//         for(int i=1; i<=amt; i++){
//             dp[i] = INT_MAX;
//             for(int coin: coins){
//                 if(coin<=i && dp[i-coin] != INT_MAX){
//                     dp[i] = min(dp[i], dp[i-coin]+1);
//                 }
//             }
//         }
//         return dp[amt] ==INT_MAX ? -1: dp[amt];
//     }
// };
