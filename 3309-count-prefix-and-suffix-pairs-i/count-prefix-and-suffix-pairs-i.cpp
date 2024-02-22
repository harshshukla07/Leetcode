class Solution {

bool isPair(vector<string>& words, int first, int second){
    string str1 = words[first], str2 = words[second];
    int size1 = words[first].size(), size2 = words[second].size();

    for(int i=0;i<size1;i++){
        if(str1[i]!=str2[i]){
            return false;
        }
    }

    for(int i=0;i<size1;i++){
        if(str1[size1-i-1]!=str2[size2-i-1]){
            return false;
        }
    }

    return true;
}

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size() ;j++){
                if(isPair(words,i,j) && i<j){
                    ans++;
                }
            }
        }
        return ans;
    }
};