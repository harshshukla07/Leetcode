class Solution {

private:
    int length(int n){
        string len = to_string(n);
        return len.size();
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(auto it: arr1){
            while(it>0){
                mp[it]++;

                it/=10;
            }
        }

        int maxi = 0;
        for(auto it: arr2){
            while(it>0){
                if(mp[it]>0){
                    maxi = max(maxi,length(it));
                }

                it/=10;
            }
        }

        return maxi;
    }
};