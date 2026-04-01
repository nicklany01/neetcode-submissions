class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1); 
        result[0] = 0;
        result[1] = 1;
        for (int i = 0; i < n+1; i++) {
            result[i] = result[i/2] + result[i%2]; // this shit is crazy, i pulled it out of my ass and it worked lol
        }
        return result;
    }
};