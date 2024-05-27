class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0,time=0,rotten=0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
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

        while(!q.empty()){

            int size = q.size();
            time++;

            for(int k=0;k<size;k++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr = r + dx[i];
                    int nc = c + dy[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=2 && grid[nr][nc]==1){
                        q.push({nr,nc});
                        vis[nr][nc]=2;
                        rotten++;
                    }
                }     
            }       

        }

        if(fresh==0){
            return 0;
        }

        return rotten==fresh?time-1:-1;

    }
};