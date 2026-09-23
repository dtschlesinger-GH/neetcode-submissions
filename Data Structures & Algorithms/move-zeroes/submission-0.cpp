class Solution {
public:
    void moveZeroes(vector<int>& nums) {
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
};