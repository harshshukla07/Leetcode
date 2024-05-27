class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0,rotten=0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
    
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        int tm = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]!=2){
                    vis[nr][nc]=2;
                    q.push({{nr,nc},t+1});
                    rotten++;
                }
            }
        }
        return fresh==rotten?tm:-1;

    }
};