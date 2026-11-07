class Solution:
    def hammingWeight(self, n: int) -> int:
        numBits = 0;
        while n > 0:
            #numBits += (n&1);
            #n >>= 1;
            n &= (n-1);
            numBits += 1;
        return numBits;