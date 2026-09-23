class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int toReturn = 0;
        int current = 0;
        for (const int element : nums) 
        {
            if (element == 1) 
            {
                current += 1;
                toReturn = max(toReturn, current);
            }
            else 
            {
                current = 0;
            }
        }
        return toReturn;
    }
};