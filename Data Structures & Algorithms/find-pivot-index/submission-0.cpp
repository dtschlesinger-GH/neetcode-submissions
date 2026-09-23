class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // subtract val at index from total, then subtract prefix sum[index - 1] from result, check if result == prefix
        vector<int> prefixSums;
        int rollingTotal = 0;

        for (const int& element : nums) 
        {
            rollingTotal += element;
            prefixSums.push_back(rollingTotal);    
        }
        int arrayTotal = prefixSums[nums.size() - 1];

        for (int i = 0; i < nums.size(); i++) 
        {
            int indexExcludedTotal = arrayTotal - nums[i];
            int previousSum = i > 0 ? prefixSums[i-1] : 0;
            if (indexExcludedTotal - previousSum == previousSum)
            {
                return i;
            }
        }
        return -1;
    }
};