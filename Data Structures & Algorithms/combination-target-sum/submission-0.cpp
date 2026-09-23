class Solution {
public:
    bool RecursiveBacktrack(const vector<int>& nums, const int target, int rollingSum, int index, vector<int>& subset, vector<vector<int>>& toReturn) 
    {
        if (rollingSum == target) 
        {
            toReturn.push_back(subset);
            return true;
        }
        if (index >= nums.size()) 
        {
            // If you ran out of numbers, this subsequence is invalid
            return false;            
        }
        if (rollingSum > target) 
        {
            // You have already exceeded the sum, no point going further
            return false;
        }

        
        // choose to continue using the same number
        rollingSum += nums[index];
        subset.push_back(nums[index]);
        RecursiveBacktrack(nums, target, rollingSum, index, subset, toReturn);

        // choose to advance to a different number
        rollingSum -= nums[index];
        subset.pop_back();
        RecursiveBacktrack(nums, target, rollingSum, index + 1, subset, toReturn);

        return true;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> toReturn;
        vector<int> currentSubset;

        RecursiveBacktrack(nums, target, 0, 0, currentSubset, toReturn);

        return toReturn;
    }
};
