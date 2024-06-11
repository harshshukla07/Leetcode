class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX,profit=INT_MIN;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minPrice){
                minPrice = prices[i];
            }
            int pofit = prices[i] - minPrice;
            profit = max(profit,pofit);
        }
        return profit;
    }
};