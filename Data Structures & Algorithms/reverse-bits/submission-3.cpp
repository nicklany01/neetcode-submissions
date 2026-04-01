class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = n;
        // divide and conquer
        result = (result >> 16) | (result << 16);
        result = ((result & 0xff00ff00) >> 8) | ((result & 0x00ff00ff) << 8);
        // 11110000 with 00001111
        result = ((result & 0xf0f0f0f0) >> 4) | ((result & 0x0f0f0f0f) << 4);
        // 11001100 with 00110011
        result = ((result & 0xcccccccc) >> 2) | ((result & 0x33333333) << 2);
        // 10101010 with 01010101
        result = ((result & 0xaaaaaaaa) >> 1) | ((result & 0x55555555) << 1);
        return result;
    }
};
