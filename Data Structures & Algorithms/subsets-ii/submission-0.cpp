class Solution {
public:
    vector<vector<int>> toReturn;

    void RecursiveBacktrack(vector<int>& nums, int index, vector<int> currentSubset) 
    {
        
        if ( index >= nums.size()) 
        {
            toReturn.push_back(currentSubset);
            return;
        }
        // for (const int num : nums) {
        //     cout << num << ", ";
        // }
        // cout << endl;
        currentSubset.push_back(nums[index]);
        RecursiveBacktrack(nums, index +1, currentSubset);
        currentSubset.pop_back();

        while (index + 1 < nums.size() && nums[index] == nums[index+1]) {
            index++;
        }
        RecursiveBacktrack(nums, index+1, currentSubset);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        RecursiveBacktrack(nums, 0, {});
        return toReturn;
    }
};
