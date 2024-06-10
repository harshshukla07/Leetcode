class Solution {

private:
    int nCr(int n, int r){
        long long res = 1;
        for(int i=0;i<r;i++){
            res = res*(n-i);
            res = res/(i+1);
        }
        return (int)(res);
    }

public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int row=1;row<=n;row++){
            vector<int>temp;
            for(int col=1;col<=row;col++){
                temp.push_back(nCr(row-1,col-1));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};