class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // numbers may and or may not be in order, so naieve approach is sort and then count
        // that's O(nlogn), so its too slow
        // given a array length n, we know that the array should contain all numbers from 0 to n, so I know the max and the min
        // I could compute a prefix sum, and then subtract from it, and whatever is remaining is what is missing.
        // that's O(n) + 0(n), so still O(n) time, but there's probably a better bitwise solution here.

        int prefixSum = 0;
        for (int i = 0; i <= nums.size(); i++) 
        {
            prefixSum += i;
        }
        for (const int num : nums)
        {
            prefixSum -= num;
        }
        return prefixSum;
    }
};
