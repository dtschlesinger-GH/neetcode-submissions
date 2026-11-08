class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // simple version, just iterate over the bits, shifting the original number right, and build the reversed by shifting up then oring with LSB
        // optimized version is probably some divide and conquer with masking?
        uint32_t toReturn = 0;
        for (int i = 0; i < 32; i++) 
        {
            toReturn <<= 1;
            toReturn |= n & 1;
            n >>= 1;
        }
        return toReturn;
    }
};
