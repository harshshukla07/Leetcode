class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x = nums[0];
        for(int i=1;i<nums.size() && nums.size()>1;i++){
            x = x^nums[i];
        }
        return x;
    }
};