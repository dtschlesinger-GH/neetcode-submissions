class Solution {
public:
    void RecursiveBacktrack(const vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& toReturn) 
    {
        if (index >= nums.size()) 
        {
            toReturn.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        RecursiveBacktrack(nums, index+1, subset, toReturn);
        subset.pop_back();
        RecursiveBacktrack(nums, index+1, subset, toReturn);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> toReturn;
        vector<int> currentSubstring;

        RecursiveBacktrack(nums, 0, currentSubstring, toReturn);        
    
        return toReturn;
    }
};
