class Solution {

private:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){

        if(i==0 && j==0){
            return grid[0][0];
        }

        if(i<0 || j<0){
            return INT_MAX;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        return dp[i][j] = grid[i][j] + min(solve(i-1,j,grid,dp),solve(i,j-1,grid,dp));

    }


public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));
        return solve(row-1,col-1,grid,dp);
    }
};