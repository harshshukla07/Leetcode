class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size_row = matrix.size(),size_col = matrix[0].size();
        for(int i=0;i<size_row;i++){
            for(int j=0;j<size_col;j++){
                if(matrix[i][j]>matrix[i][size_col-1]){
                    i++;
                    j=0;
                }
                else if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};