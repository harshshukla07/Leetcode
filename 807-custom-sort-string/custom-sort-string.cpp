class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        string ans = "";
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<order.size();i++){
            while(mp[order[i]]>0){
                ans.push_back(order[i]);
                mp[order[i]]--;
            }
        }
        for(auto it: mp){
            while(it.second>0){
                ans.push_back(it.first);
                it.second--;
            }
        }
        return ans;
    }
};