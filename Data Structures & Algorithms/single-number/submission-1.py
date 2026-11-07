class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        toReturn = 0;
        for number in nums:
            toReturn ^= number;

        return toReturn;
        