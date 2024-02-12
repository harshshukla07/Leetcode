class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int freq = 0, ans = -1;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto it: mp){

            if(it.second==freq){
                if(it.first<ans && it.first%2==0){
                    ans = it.first;
                }
            }

            else if(it.second>freq && (it.first)%2==0){
                freq = it.second;
                ans = it.first;

            }
        }
        return ans;

    }
};