class Solution {

private:
    void helper(int num, int k, int n, vector<int> ds, vector<vector<int>>& ans){
        if(num>9){
            if(n==0 && ds.size()==k){
                ans.push_back(ds);
            }
            return;
        }
        helper(num+1,k,n,ds,ans);
        n = n-num;
        ds.push_back(num);
        helper(num+1,k,n,ds,ans);
        ds.pop_back();
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(1,k,n,ds,ans);
        return ans;

    }
};