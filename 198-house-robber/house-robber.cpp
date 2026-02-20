//Approach-1 (Recur + Memo)
class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums, int i, int& n) {
        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int take = nums[i] + solve(nums, i+2, n); //steals ith house and moves to i+2 (because we can't steal adjacent)
        int skip = solve(nums, i+1, n); //skips this house, now we can move to adjacent next house
        
        return dp[i]=max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        // memset(dp, -1, sizeof(dp));
        for(int i=0;i<101;i++){
            dp[i]=-1;
        }
        return solve(nums, 0, n);
    }
};


// //Approach-2 (Bottom up)
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
        
//         if(n == 1)
//             return nums[0];
        
//         vector<int> t(n+1);
//         //t[i] = max profit till house i
        
//         t[0] = 0;
//         t[1] = nums[0];
        
//         for(int i = 2; i<=n; i++) {
            
//             int skip  = t[i-1];
//             int steal = nums[i-1] + t[i-2];
          
//             t[i] = max(skip, steal); //max(skip, steal)
//             /*
//                 SKIP  : If we skip this house,  then we have money till previous house  =  t[i-1]
//                 STEAL : If we steal this house, then we can't take prev profit, we can take till (i-2)th house profit = t[i-2]
//             */
//         }
        
//         return t[n];
        
//     }
// };
