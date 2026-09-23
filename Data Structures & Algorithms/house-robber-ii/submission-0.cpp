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
        houseTotals[currentHouse] = max(RecursiveBacktrack(currentHouse + 1, houseTotals, houseValues), 
                                        currentHouseValue + RecursiveBacktrack(currentHouse + 2, houseTotals, houseValues));
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
        int temp = nums[0];
        nums.erase(nums.begin());
        int noFirstHouse = RecursiveBacktrack(0, houseTotals, nums);
        nums.insert(nums.begin(), temp);
        nums.pop_back();
        houseTotals.clear();
        int firstHouse = RecursiveBacktrack(0, houseTotals, nums);
        return max(noFirstHouse, firstHouse);
    }
};
