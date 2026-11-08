class Solution:
    def countBits(self, n: int) -> List[int]:
        numBits = [0] * (n+1);
        for index in range(0, n + 1):
            currentNum = index;
            while (currentNum != 0):
                currentNum &= currentNum - 1;
                numBits[index] += 1;
        return numBits;