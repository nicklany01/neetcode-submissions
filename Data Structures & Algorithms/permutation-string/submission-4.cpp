#include <array>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        array<int, 26> freq = {0};
        int n = s1.size(), m = s2.size();
        for (int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
        } 
        int l = 0, r = 0;
        // budget and debt system
        while (r < m) {
            // spend from bank
            freq[s2[r] - 'a']--;
            // get money back until debt is paid off
            while (freq[s2[r] - 'a'] < 0) {
                freq[s2[l++] - 'a']++;
            }
            if (r - l + 1 == n) return true; 
            r++;
        }
        return false;
    }
};
