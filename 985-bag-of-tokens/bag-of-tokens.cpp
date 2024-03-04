class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int left = 0, right = tokens.size()-1;
        int score = 0, max_score = 0;
        while(left<=right){
            if(power>=tokens[left]){
                score+=1;
                power-=tokens[left];
                left++;
                max_score = max(max_score,score);
            }
            else if(score>=1){
                power+=tokens[right];
                score-=1;
                right--;
            }
            else{
                break;
            }
        }
        return max_score;
    }
};