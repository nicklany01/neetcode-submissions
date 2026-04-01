#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> map1;
        std::unordered_map<char, int> map2;
        for (char c : s) {
            map1[c] += 1;
        }
        for (char c : t) {
            map2[c] += 1;
        }
        if (map1 == map2) {
            return true;
        }
        return false;
    }
};
