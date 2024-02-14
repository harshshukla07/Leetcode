#include<queue>
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos;
        queue<int> neg;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                pos.push(nums[i]);
            }
            else{
                neg.push(nums[i]);
            }
        }
        for(int j=0;j<nums.size();j++){
            if(j%2==0){
                nums[j] = pos.front();
                pos.pop();
            }
            else{
                nums[j] = neg.front();
                neg.pop();
            }
        }
        return nums;
    }
};