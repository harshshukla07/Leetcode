class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int count = 0,total=0;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                q.push({i,0});
                count++;
                vis[i][0] = 1;
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                q.push({i,m-1});
                count++;
                vis[i][m-1] = 1;
            }
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                q.push({0,j});
                count++;
                vis[0][j] = 1;
            }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                q.push({n-1,j});
                count++;
                vis[n-1][j] = 1;
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int dx[] = {0,1,0,-1};
            int dy[] = {1,0,-1,0};
            for(int i = 0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                    count++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    total++;
                }
            }
        }
        return total - count;
    }
};