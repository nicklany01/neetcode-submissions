class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int max = 0;
        function<void(int,int)> expand = [&](int l, int r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r-l-1 > max) {
                max = r-l-1;
                start = l+1;
            }
        };
        for (int i = 0; i < s.size(); i++) {
            // expand around the center, update new max anytime its found
            // check odd
            expand(i,i);
            // check even
            expand(i,i+1);
        }
        return s.substr(start, max);
    }
};
