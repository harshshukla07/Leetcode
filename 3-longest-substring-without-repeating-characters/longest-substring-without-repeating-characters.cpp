class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;

        int left = 0, right = 0, res = 0;

        while(right<s.length()){
            char r = s[right];
            freq[r]++;
            while(freq[r]>1){
                char l = s[left];
                freq[l]--;
                left++;
            }

            res = max(res,right-left+1);

            right++;
        }
        return res;
    }
};