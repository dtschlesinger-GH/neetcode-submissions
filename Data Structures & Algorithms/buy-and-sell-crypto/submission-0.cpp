class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leftIndex = 0;
        int rightIndex = 1;
        int sumTotal = 0;
        int maxTotal = 0;
        if (prices.size() == 1) 
        {
            return 0;
        }
        if (prices.size() == 2) 
        {
            if (prices[0] < prices[1]) 
            {
                return prices[1] - prices[0];
            }
        }

        // take price[i+1] - price[i], add to total.  
        // if total goes negative, move left index to i+1.
        
        for (; rightIndex < prices.size(); rightIndex++) 
        {
            int windowTotal = prices[rightIndex] - prices[leftIndex];
            maxTotal = max(maxTotal, windowTotal);
            if (windowTotal < 0) 
            {
                sumTotal = 0;
                leftIndex = rightIndex;
            }
        }
        return maxTotal;
    }
};
