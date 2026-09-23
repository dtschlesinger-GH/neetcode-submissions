class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> foundNums{};
        for (int index = 0; index < nums.size(); index++) {
            if (!foundNums.contains(nums[index])) 
            {
                foundNums.insert(nums[index]);
            }
            else {
                return true;
            }
        }
        return false;
    }

};