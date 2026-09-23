class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int leftIdx = 0;
        int rightIdx = 0;

        while (rightIdx < nums.size()) 
        {
            int count = 1;
            while (rightIdx + 1 < nums.size() && nums[rightIdx] == nums[rightIdx + 1]) {
                rightIdx++;
                count++;
            }

            for (int i = 0; i < min(2, count); i++) {
                nums[leftIdx] = nums[rightIdx];
                leftIdx++;
            }
            rightIdx++;
        }
        return leftIdx;
    }
};