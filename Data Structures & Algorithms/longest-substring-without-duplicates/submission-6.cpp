class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0, l = 0;
        set<char> chars;
        int result = 1;
        if (s.size() == 0) return 0;
        while (r < s.size()) {
            if (chars.count(s[r])) {
                chars.erase(s[l]);
                l++;
            } else {
                chars.insert(s[r++]);
                result = max(result, (int)chars.size());
            }
            cout << result;
        }
        return result;
    }
};
