class Solution {

private:
    int solve(int n, vector<int>& nums, vector<int> &dp){

        dp[0] = nums[0];

        // if(n==0){
        //     return nums[n];
        // }

        // if(n<0){
        //     return 0;
        // }

        for(int i = 1; i<n; i++){
            int notpick = 0 + dp[i-1];

            int pick = nums[i];
            if(i>1){
                pick = pick + dp[i-2];
            }
            dp[i] = max(pick,notpick);
        }

        

        return dp[n-1];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        return solve(n,nums,dp);
    }
};