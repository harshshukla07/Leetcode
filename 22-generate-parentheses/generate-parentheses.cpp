class Solution {

private:
    void helper(int left, int right, string curr,int n){
        if(right == n){
            str.push_back(curr);
        }
        if(left<n){
            helper(left+1,right,curr+'(',n);
        }
        if(right<n && right<left){
            helper(left,right+1,curr+')',n);
        }


    }

public:
    vector<string> str;
    vector<string> generateParenthesis(int n) {
        
        helper(0,0,"",n);
        return str;
        
    }
};