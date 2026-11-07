class Solution {
public:
    int hammingWeight(uint32_t n) {
        //Naieve approach is just iterate through the number, and count the number of 1s.
        //correct approach is to get the MSB or LSB each time, and use a counter for that
        //I will write both approaches, just for completeness

        int numBits = 0;
        while (n > 0) 
        {
            numBits += (n & 1);
            n >>= 1;
        }
        return numBits;
    }
};
