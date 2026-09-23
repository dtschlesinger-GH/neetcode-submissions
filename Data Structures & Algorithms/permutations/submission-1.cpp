class Solution {
public:
    vector<vector<int>> toReturn;

    void RecursiveBacktrack(vector<int> nums, vector<int> currentPermutation, vector<bool> indiciesUsed) 
    {
        if (currentPermutation.size() >= nums.size()) 
        {
            toReturn.push_back(currentPermutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++) 
        {
            if (indiciesUsed[i] == true) 
            {
                continue;
            }
            indiciesUsed[i] = true;
            currentPermutation.push_back(nums[i]);
            RecursiveBacktrack(nums, currentPermutation, indiciesUsed);
            indiciesUsed[i] = false;
            currentPermutation.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // this is backtracking
        // unique, so we don't need to worry about skipping duplicate numbers
        // the recursion function will hinge on picking one number from the set, a different number each time
        // Can we just do i recursive calls, where i is the index we are looking at in a for loop, then pass it a copy with that index removed?
        vector<bool> indiciesUsed(nums.size(), false);
        RecursiveBacktrack(nums, {}, indiciesUsed);
        return toReturn;
    }
};
