class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1); 
        result[0] = 0;
        result[1] = 1;
        for (int i = 0; i < n+1; i++) {
            result[i] = result[i >> 1] + (i & 1);
        }
        return result;
    }
};