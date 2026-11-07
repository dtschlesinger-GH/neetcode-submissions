class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Use associative and cancellation properites of xor
        int toReturn = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            toReturn ^= nums[i];
        }

        return toReturn;
    }
};
