class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long area=0;
        for(int i=0;i<bottomLeft.size();i++){
            for(int j=i+1;j<bottomLeft.size();j++){
                long long minimum_x = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long maximum_x = min(topRight[i][0], topRight[j][0]);
                long long minimum_y = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long maximum_y = min(topRight[i][1], topRight[j][1]);
                
                if(minimum_x<maximum_x && minimum_y<maximum_y){
                    long long s = min(maximum_x-minimum_x, maximum_y-minimum_y);
                    area = max(area, s*s);
                }
            }
        }
        return area;
    }
};