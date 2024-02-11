class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());

        vector<int>dp(n,1);
        vector<int>hash(n,0);
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev = 0;prev<i;prev++){
                if(arr[i]%arr[prev]==0 && 1+dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
        }

        int ans = -1;
        int last = -1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans = dp[i];
                last = i;
            }
        }

        vector<int> temp;
        temp.push_back(arr[last]);
        while(hash[last]!=last){
            last = hash[last];
            temp.push_back(arr[last]);
        }

        reverse(temp.begin(),temp.end());
        return temp;
    }
};