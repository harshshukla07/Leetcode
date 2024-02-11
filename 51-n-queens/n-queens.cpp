class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtracking(board, 0);
        return res;
    }
    void backtracking(vector<string>& board, int row) { 
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        for (int col=0; col < board.size(); col++) {
            if (!valid(board, row, col)) continue;
            board[row][col]='Q';
            backtracking(board, row+1);
            board[row][col]='.';
        }
    }
    bool valid(vector<string>& board, int row, int col) {
        int n=board.size();
        for (int r=row-1; r >= 0; r--) {
            if (board[r][col] == 'Q') return false;
        }
        for (int r=row-1, c=col-1; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == 'Q') return false;
        }
        for (int r=row-1, c=col+1; r >= 0 && c < n; r--, c++) {
            if (board[r][c] == 'Q') return false;
        }
        return true;
    }
};