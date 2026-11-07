public class Solution {
    public int HammingWeight(uint n) {
        int numBits = 0;
        // while (n > 0) 
        // {
        //     numBits += ((int)n & 1);
        //     n >>= 1;
        // }
        // return numBits;

        while (n > 0) 
        {
            n &= (n-1);
            numBits++;
        }
        return numBits;
    }
}
