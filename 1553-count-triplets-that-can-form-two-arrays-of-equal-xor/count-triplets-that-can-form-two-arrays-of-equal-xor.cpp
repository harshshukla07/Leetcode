class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXOR(arr.begin(), arr.end());
        prefixXOR.insert(prefixXOR.begin(), 0);
        int size = prefixXOR.size();
        int count = 0;

        for (int i = 1; i < size; ++i) prefixXOR[i] ^= prefixXOR[i - 1];

        unordered_map<int, int> countMap, totalMap;

        for (int i = 0; i < size; ++i) {
            count +=
                countMap[prefixXOR[i]]++ * (i - 1) - totalMap[prefixXOR[i]];

            totalMap[prefixXOR[i]] += i;
        }

        return count;
    }
};