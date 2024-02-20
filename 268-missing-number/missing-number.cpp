class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actual_sum = n*(n+1)/2,sum=0;
        for(int i=0;i<n;i++){
            sum = sum + nums[i];
        }
        return (actual_sum - sum);
    }
};