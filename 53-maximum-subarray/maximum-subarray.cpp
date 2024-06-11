class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN,maxi=0;
        for(int i=0;i<nums.size();i++){
            if(maxi<0){
                maxi=0;
            }
            maxi += nums[i];
            sum = max(sum,maxi);
        }
        return sum;
    }
};