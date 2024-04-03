class Solution {

private:
    bool solve(int ind, int row, int col, vector<vector<char>>& board, string word, int m, int n){
        if(ind == word.length()) return true;

        if(row<0 || col<0 || row==m || col==n || board[row][col]!=word[ind] || board[row][col]=='#'){
            return false;
        }

        char ch = board[row][col];
        board[row][col] = '#';

        bool up    = solve(ind+1,row-1,col,board,word,m,n);
        bool down  = solve(ind+1,row+1,col,board,word,m,n);
        bool left  = solve(ind+1,row,col-1,board,word,m,n);
        bool right = solve(ind+1,row,col+1,board,word,m,n);

        board[row][col] = ch;

        return up|| down || left || right;

    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(0,i,j,board,word,m,n)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};