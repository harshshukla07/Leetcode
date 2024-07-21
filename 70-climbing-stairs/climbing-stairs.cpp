class Solution {

// private:
//     int solve(int n,vector<int>& dp){
//         if(n<=1){
//             return 1;
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         dp[n] = solve(n-1,dp) + solve(n-2,dp);
//         return dp[n];
//     }

public:
    int climbStairs(int n) {
        // vector<int> dp(n+1);
        // dp[0] = 1;
        // dp[1] = 1;
        int prev2 = 1,prev1 = 1, curr;
        for(int i=2;i<=n;i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};