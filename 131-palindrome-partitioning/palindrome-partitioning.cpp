class Solution {
public:

    void solve(string s, vector<string> output, vector<vector<string>>& ans, int index){
        if(index>=s.length()){
            ans.push_back(output);
            return;
        }

        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                output.push_back(s.substr(index, i-index+1));
                solve(s,output,ans,i+1);
                output.pop_back();
            }
        }
    }

    bool isPalindrome(string str, int start, int end){
        while(start<=end){
            if(str[start++]!=str[end--]){
            return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        solve(s,output,ans,0);
        return ans;
    }
};