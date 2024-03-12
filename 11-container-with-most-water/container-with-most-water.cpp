class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0, back = height.size()-1, maxi = INT_MIN;
        while(front<back){
            int line = min(height[front],height[back]);
            int area = line * (back-front);
            maxi = max(maxi,area);
            if(height[front]<height[back]){
                front++;
            }
            else{
                back--;
            }
        }
        return maxi;
    }
};