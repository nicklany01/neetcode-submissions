class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        for (int i = 0; i < strs.size(); i++) {
            int stringSize = strs[i].size();
            encodedString.push_back(stringSize);
            for (int j = 0; j < stringSize; j++) {
                encodedString.push_back((strs[i][j]+10) % 256);
            }
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedStrings;
        for (int i = 0; i < s.size(); i++) {
            int stringSize = (uint8_t)s[i];
            string decodedString = "";
            int end = i + stringSize;
            while (i < end) {
                i++;
                decodedString.push_back((s[i]-10) % 256);
            }
            decodedStrings.push_back(decodedString);
        }
        return decodedStrings;
    }
};