class Solution {

private:
    void helper(int ind, string digits, string output, vector<string> map, vector<string>& ans){
        if(ind>=digits.length()){
            ans.push_back(output);
            return;
        }
        int temp = digits[ind]-'0';
        string str = map[temp];
        for(int i=0;i<str.size();i++){
            output+=str[i];
            helper(ind+1,digits,output,map,ans);
            output.pop_back();
        }

    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return {};
        }
        vector<string> map = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string output = "";
        helper(0,digits,output,map,ans);
        return ans;
    }
};