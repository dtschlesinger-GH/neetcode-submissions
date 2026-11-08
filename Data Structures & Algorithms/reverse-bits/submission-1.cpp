class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // simple version, just iterate over the bits, shifting the original number right, and build the reversed by shifting up then oring with LSB
        // optimized version is probably some divide and conquer with masking?
        n = ((n >> 1) & 0x55555555) | ((n & 0x55555555) << 1);
        n = ((n >> 2) & 0x33333333) | ((n & 0x33333333) << 2);
        n = ((n >> 4) & 0x0f0f0f0f) | ((n & 0x0f0f0f0f) << 4);
        n = ((n >> 8) & 0x00ff00ff) | ((n & 0x00ff00ff) << 8);
        n = (n >> 16) | (n << 16);
        return n;
    }
};
