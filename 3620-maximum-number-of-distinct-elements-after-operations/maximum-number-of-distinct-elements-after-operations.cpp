class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        if (k == 0) {
            return unordered_set<int>(nums.begin(), nums.end()).size();
        }

        sort(nums.begin(), nums.end());
        long long curr = nums[0] - k;
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            long long minPossible = nums[i] - k;
            long long maxPossible = nums[i] + k;
            
            if (curr + 1 > maxPossible) {
                continue;
            }
            if (curr + 1 >= minPossible) {
                curr++;
                count++;
            } else {
                curr = minPossible;
                count++;
            }
        }
        return count;
    }
};