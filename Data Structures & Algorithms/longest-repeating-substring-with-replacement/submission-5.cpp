#include <array>
class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 26> freq = {0};
        int l = 0, r = 0;
        int maxSub = 1;
        // open the window until k isnt enough, move l to the right, if k is enough, move r to the right. end when r hits end
        while (r < s.size()) {
            freq[s[r] - 'A'] += 1;
            // check how many replacements would be needed
            int maxFreq = 0;
            int totalFreq = 0;
            for (int i = 0; i < freq.size(); i++) {
                maxFreq = max(maxFreq, freq[i]);
                totalFreq += freq[i];
            }
            if (totalFreq - maxFreq > k) {
                freq[s[l++] - 'A']--;
            } else {
                maxSub = max(maxSub, r - l + 1);
            }
            r++;
        }
        return maxSub;
    }
};
