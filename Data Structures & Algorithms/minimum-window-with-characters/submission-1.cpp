class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for (char c : t) {
            freq[c]++;
        }
        int min = s.size();
        int l = 0, r = 0;
        int remaining = t.size();
        int minLen = INT_MAX, minStart = 0;
        // if we dont have enough chars in s, keep going right, otherwise try to shrink it to a smaller size
        while (r < s.size()) {
            // if this is one of the chars needed
            if (freq[s[r]] > 0) remaining--;
            freq[s[r++]]--;
            while (remaining == 0) {
                if (r - l < minLen) {
                    minLen = r - l;
                    minStart = l;
                }
                freq[s[l]]++;
                if (freq[s[l]] > 0) remaining++;
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
