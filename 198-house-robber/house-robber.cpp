class Solution
{

    // private:
    //     int solve(int ind, vector<int> nums, vector<int> &dp) {
    //         if(ind==0){
    //             return nums[ind];
    //         }

    //         if(ind==-1){
    //             return 0;
    //         }

    //         if(dp[ind]!=-1){
    //             return dp[ind];
    //         }
    //         int first = nums[ind] + solve(ind-2,nums,dp);
    //         int second = 0 + solve(ind-1,nums,dp);

    //         return dp[ind] = max(first,second);
    //     }

    public:
        int rob(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> dp(n + 1, -1);
            dp[0] = nums[0];
            for(int i=1;i<n;i++){
                int pick = nums[i];
                if(i>1){
                    pick+= dp[i-2];
                }
                int notPick = 0;
                notPick+=dp[i-1];

                dp[i] = max(pick,notPick);

            }
            return dp[n-1];
        }
};