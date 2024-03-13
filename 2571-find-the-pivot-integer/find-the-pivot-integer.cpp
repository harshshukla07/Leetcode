class Solution {
public:
    int pivotInteger(int n) {
        int totSum = n*(n+1)/2;
        int pivot = -1;
        for(int i=0;i<=n;i++){
            int tempSum = i*(i+1)/2;
            if(tempSum == totSum-tempSum + i){
                pivot = i;
                break;
            }
        }
        return pivot;
    }
};