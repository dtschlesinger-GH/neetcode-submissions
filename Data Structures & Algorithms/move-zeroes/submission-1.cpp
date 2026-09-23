class Solution {
public:
    void ExtraSpaceImplementation(vector<int>& nums) 
    {
        queue<int> nonZeros;

        for (const int& element : nums) 
        {
            if (element != 0) 
            {
                nonZeros.push(element);
            }
        }
        for (int i = 0; i < nums.size(); i++) 
        {
            if (!nonZeros.empty()) 
            {
                nums[i] = nonZeros.front();
                nonZeros.pop();
                continue;
            }
            nums[i] = 0;
        }
    }

    void moveZeroes(vector<int>& nums) 
    {
        for (int leftIndex = 0, rightIndex = 0; rightIndex < nums.size(); rightIndex++) 
        {
            if (nums[rightIndex]) 
            {
                swap(nums[leftIndex++], nums[rightIndex]);
            }
        }
    }
};