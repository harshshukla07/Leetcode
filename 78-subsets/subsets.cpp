class Solution {

private:
    void helper(vector<int> nums,vector<int> output,int index,vector<vector<int>>&ans){

        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }

        helper(nums,output,index+1,ans);

        int temp = nums[index];
        output.push_back(temp);
        helper(nums,output,index+1,ans);

    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        helper(nums,output,0,ans);
        return ans;
    }
};