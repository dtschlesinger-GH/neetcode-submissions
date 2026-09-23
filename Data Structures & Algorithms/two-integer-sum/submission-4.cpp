class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        std::unordered_map<int, int> recordedNums;

        for (int index = 0; index < nums.size(); index++) {
            int diff = target - nums[index];
            if (recordedNums.count(diff) > 0 && recordedNums[diff] != index) {
                return {recordedNums[diff], index};
            }
            recordedNums.insert({nums[index], index});
        }
        return {};
    }
};
