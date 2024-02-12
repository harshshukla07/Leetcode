class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ele;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                ele = nums[i];
                count = 1;
            }
            else if(nums[i]==ele){
                count++;
            }
            else if(nums[i]!=ele){
                count--;
            }
        }
        return count>0 ? ele:-1;
    }
};