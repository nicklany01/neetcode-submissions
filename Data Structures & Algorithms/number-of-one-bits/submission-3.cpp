class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            // subtracting 1 flips rightmost 1 bit from 1 to 0, then everything on the right is set to 1.
            n &= n - 1; // remove only the rightmost 1 bit
            count++;
        }
        return count;
    }
};