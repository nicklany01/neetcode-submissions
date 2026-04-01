class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            for (int j = i; j < temperatures.size(); j++) {
                if (temperatures[j] > temperatures[i]) {
                    result[i] = j - i;
                    break;
                } 
            }
        }
        return result;
    }
};
