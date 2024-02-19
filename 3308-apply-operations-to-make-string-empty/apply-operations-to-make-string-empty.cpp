class Solution {
public:
    string lastNonEmptyString(string s) {

        unordered_map<char,int> mp; 
        int maxi=0; 
        for(auto it:s){
            mp[it]++;
           
            maxi=max(mp[it],maxi);
        }
        
        string ans="";

        for(int i=s.size()-1;i>=0;i--){
            if(mp[s[i]]==maxi){
                
                ans.push_back(s[i]);
                
                mp[s[i]]--;
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};