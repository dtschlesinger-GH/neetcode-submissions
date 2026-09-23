class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Naive solution is mult everything together, then divide by our index
        // if val at our index is 0, return the mult num
        vector<int> toReturn;
        int numZeros = 0;
        int zeroTotal = 0;

        int total = 1;
        for (const int& element : nums) 
        {
            if (element == 0) 
            {
                numZeros++;
                if (numZeros > 1) 
                {
                    total = 0;
                }
                continue;
            }
            total *= element;
        }
        
        for (const int& element : nums) 
        {
            if (numZeros == 1) 
            {
                toReturn.push_back(element == 0 ? total : 0);
            }
            else 
            {
                toReturn.push_back(element == 0 ? total : total / element);
            }
        }
        return toReturn;
    }
};
