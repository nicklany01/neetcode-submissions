class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>, vector<string>> mainMap;

        for (string s : strs) {
            map<char, int> freq;
            for (char c : s) {
                freq[c]++;
            }
            mainMap[freq].push_back(s);
        } 

        vector<vector<string>> result;
        for (auto [key, vec] : mainMap) {
            result.push_back(vec);
        }
        return result;
    }
};
