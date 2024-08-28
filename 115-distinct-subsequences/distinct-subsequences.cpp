class Solution {

private:
    int solve(int ind1, int ind2, string s, string t, vector<vector<int>>& dp){
        if(ind2<0){
            return 1;
        }
        if(ind1<0){
            return 0;
        }

        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }

        int ans = 0;
        if(s[ind1]==t[ind2]){
            ans = (solve(ind1-1,ind2,s,t,dp) + solve(ind1-1,ind2-1,s,t,dp));
        }
        else{
            ans = solve(ind1-1,ind2,s,t,dp);
        }

        dp[ind1][ind2] = ans;
        return dp[ind1][ind2];
    }

public:
    int numDistinct(string s, string t) {
        int ss = s.size(), ts = t.size();
        vector<vector<int>>dp(ss,vector<int>(ts,-1));
        return solve(ss-1,ts-1,s,t,dp);
    }
};