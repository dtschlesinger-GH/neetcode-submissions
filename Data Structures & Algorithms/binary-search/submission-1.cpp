class Solution {
public:
    int search(vector<int>& nums, int target) {
        int middleIndex = nums.size() / 2;
        int rightIndex = nums.size() - 1;
        int leftIndex = 0;

        while (leftIndex <= rightIndex ) 
        {
            middleIndex = leftIndex + ((rightIndex - leftIndex) / 2);

            if (nums[middleIndex] == target) 
            {
                return middleIndex;
            }
            else if (nums[middleIndex] > target) 
            {
                rightIndex = middleIndex - 1;
            }
            else 
            {
                leftIndex = middleIndex + 1;
            }
        }        
        return -1;
    }
};
