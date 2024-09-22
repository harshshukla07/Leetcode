class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string, int> mp;
        for(int i=0;i<bannedWords.size();i++){
            mp[bannedWords[i]]++;
        }
        int ans = 0;
        for(int i=0;i<message.size();i++){
            string temp = message[i];
            if(mp[temp]>=1){
                ans++;
            }
        }
        if(ans>=2){
            return true;
        }
        return false;
    }
};