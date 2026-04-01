#include <array>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        array<int, 26> freq = {0};
        array<int, 26> curr_freq = {0};
        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a'] += 1;
            curr_freq[s2[i] - 'a'] += 1;
        }
        int l = 0, r = s1.size() - 1;
        while (r < s2.size()) {
            bool match = true;
            for (int i = 0; i < freq.size(); i++) {
                cout << curr_freq[i];
                if (curr_freq[i] != freq[i]) {
                    match = false;
                }
            }
            cout << "\n";
            if (match) {
                return true;
            }
            r++;
            curr_freq[s2[r] - 'a'] += 1;
            curr_freq[s2[l] - 'a'] -= 1;
            l++;
        }
        return false;
    }
};
