class Solution {

private:
    bool isPrime(int n){
        for(int p = 2; p * p <= n; p++){
            if(n % p == 0){
                return false;
            }
        }
        return true;
    }

public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int,int> mp;
        vector<int> posR = {-1,-1,-1,0,1,1,1,0};
        vector<int> posC = {-1,0,1,1,1,0,-1,-1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<8; k++){
                    int row = i, col = j, num=0;
                    while(row>=0 && row<n && col>=0 && col<m){
                        num = (10*num) + mat[row][col];
                        if(num>10 && isPrime(num)){
                            mp[num]++;
                        }
                        row+=posR[k];
                        col+=posC[k];
                    }
                }
            }
        }

        int ans = -1;
        int maxFreq = 0;

        for(auto it: mp){
            if(it.second>maxFreq){
                ans = it.first;
                maxFreq = it.second;
            }
            else if(it.second==maxFreq && it.first>ans){
                ans = it.first;
            }
        }

        return ans;
    }
};