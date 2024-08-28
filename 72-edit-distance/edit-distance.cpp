class Solution {

private:
    int solve(int ind1, int ind2, string word1, string word2, vector<vector<int>>& dp){
        if(ind1<0){
            return ind2+1;
        }
        if(ind2<0){
            return ind1+1;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }

        if(word1[ind1]==word2[ind2]){
            return dp[ind1][ind2] = 0 + solve(ind1-1,ind2-1,word1,word2,dp);
        }
        else{
            return dp[ind1][ind2] = 1 + min(solve(ind1-1,ind2,word1,word2,dp),min(solve(ind1,ind2-1,word1,word2,dp),solve(ind1-1,ind2-1,word1,word2,dp)));
        }

        return dp[ind1][ind2];
    }

public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2=word2.size();
        vector<vector<int>>dp(s1,vector<int>(s2,-1));
        return solve(s1-1,s2-1,word1,word2,dp);
    }
};