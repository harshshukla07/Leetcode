class Solution {
public:
    int scoreOfString(string s) {
        int temp;
        int sum = 0;
        for(int i=0;i<s.size()-1;i++){
            int diff = 0;
            diff = abs(s[i] - s[i+1]);
            sum += diff;
        }
        return sum;
    }
};