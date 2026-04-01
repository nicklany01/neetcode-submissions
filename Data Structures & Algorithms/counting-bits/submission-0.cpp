class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1); 
        // 01 10 11 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111
        // 1 bit is subset of 2 bit number
        result[0] = 0;
        result[1] = 1;
        for (int i = 0; i < n+1; i++) {
            result[i] = result[i/2] + result[i%2];
        }
        return result;
    }
};