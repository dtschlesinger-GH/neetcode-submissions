class Solution {
public:
    int RecursiveBacktrack(int currentHouse, unordered_map<int, int>& houseTotals, const vector<int>& houseValues) 
    {
        if (currentHouse >= houseValues.size()) 
        {
            // we exceeded house bounds, no value
            return 0;
        }

        if (houseTotals.contains(currentHouse)) 
        {
            return houseTotals[currentHouse];
        }

        int currentHouseValue = houseValues[currentHouse];
        int maxSubproblemVal = 0;
        for (int i = currentHouse + 2; i < houseValues.size(); i++) 
        {
            maxSubproblemVal = max(maxSubproblemVal, RecursiveBacktrack(i, houseTotals, houseValues));
        }
        houseTotals[currentHouse] = maxSubproblemVal + currentHouseValue;
        return houseTotals[currentHouse];
    }

    int rob(vector<int>& nums) {
        // we can't go backwards, so we will always be advancing forward, but we can advance forward by 2 + i each time
        // nums are also only ever positive, so we would never want to start on any index that isn't 0 or 1 to maximize
        if (nums.size() == 1) 
        {
            return nums[0];
        }

        unordered_map<int, int> houseTotals;
        return max(RecursiveBacktrack(0, houseTotals, nums), RecursiveBacktrack(1, houseTotals, nums));
    }
};
