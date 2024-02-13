class Solution {

private:
bool isPalindrome(string s, int start, int end){
    while(start<end){
        if(s[start++]!=s[end--]){
        return false;
        }
    }
    return true;
}
public:
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(int i=0;i<words.size();i++){
            string last = words[i];
            if(isPalindrome(words[i],0,last.size()-1)){
                ans = words[i];
                break;
            }
        }
        return ans;
    }
};