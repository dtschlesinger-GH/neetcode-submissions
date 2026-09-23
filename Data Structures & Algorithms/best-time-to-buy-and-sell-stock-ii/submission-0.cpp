class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        for (int i = 1; i < prices.size(); i++) 
        {
            int priceFlux = prices[i] - prices[i-1];
            if (priceFlux > 0) 
            {
                totalProfit += priceFlux;
            }
        }
        return totalProfit;        
    }
};