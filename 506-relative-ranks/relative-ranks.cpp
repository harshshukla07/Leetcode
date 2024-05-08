class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int N = score.size();
        vector<int> scoreCopy(N);
        copy(score.begin(), score.end(), scoreCopy.begin());
        
        unordered_map<int, int> scoreToIndex;
        for (int i = 0; i < N; i++) {
            scoreToIndex[scoreCopy[i]] = i;
        }
        
        sort(scoreCopy.begin(), scoreCopy.end(), greater<int>());

        vector<string> rank(N);
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                rank[scoreToIndex[scoreCopy[i]]] = "Gold Medal";
            } else if (i == 1) {
                rank[scoreToIndex[scoreCopy[i]]] = "Silver Medal";
            } else if (i == 2) {
                rank[scoreToIndex[scoreCopy[i]]] = "Bronze Medal";
            } else {
                rank[scoreToIndex[scoreCopy[i]]] = to_string(i + 1);
            }
        }
        
        return rank;
    }
};