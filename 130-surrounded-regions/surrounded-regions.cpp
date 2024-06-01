class Solution {

private:
    void dfs(int row, int col, vector<int> dx, vector<int> dy, vector<vector<int>> &vis, vector<vector<char>>& board){
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<4;i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,dx,dy,vis,board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,dx,dy,vis,board);
            }

            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,dx,dy,vis,board);
            }
        }

        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,dx,dy,vis,board);
            }

            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,dx,dy,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
                
            }
        }

    }
};