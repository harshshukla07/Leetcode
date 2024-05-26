class Solution {

private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& ans, vector<int> drow, vector<int> dcol, int initialColor){
        ans[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4;i++){
            int row = sr + drow[i];
            int col = sc + dcol[i];

            if(row>=0 && row<n && col>=0 && col<m && image[row][col]==initialColor && ans[row][col]!=color ){
                dfs(image,row,col,color,ans,drow,dcol,initialColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<int> drow = {0,1,0,-1};
        vector<int> dcol = {1,0,-1,0};
        dfs(image,sr,sc,color,ans,drow,dcol,initialColor);
        return ans;
    }
};