class Solution {

private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& ans, vector<int> dx, vector<int> dy, int ini){
        ans[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4;i++){
            int row = sr + dx[i];
            int col = sc + dy[i];
            if(row>=0 && row<n && col>=0 && col<m && image[row][col]==ini && ans[row][col]!=color){
                dfs(image,row,col,color,ans,dx,dy,ini);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int initialcolor = image[sr][sc];
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        dfs(image,sr,sc,color,ans,dx,dy,initialcolor);
        return ans;

    }
};