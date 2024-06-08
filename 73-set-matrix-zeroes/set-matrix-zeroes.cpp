class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> placeHolder = matrix;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int zrow,zcol;
                if(placeHolder[i][j]==0){
                    zrow = i;
                    zcol = j;
                    for(int a=0;a<col;a++){
                        matrix[zrow][a] = 0;
                    }
                    for(int b=0;b<row;b++){
                        matrix[b][zcol] = 0;
                    }
                }
            }
        }
    }
};