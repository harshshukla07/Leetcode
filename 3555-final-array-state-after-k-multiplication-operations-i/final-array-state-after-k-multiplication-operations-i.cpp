class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            int min = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<nums[min] && min!=i){
                    min = i;
                }
            }
            nums[min] = multiplier * nums[min];
        }
        return nums;
    }
};