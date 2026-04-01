class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ind_f = 0;
        int ind_b = numbers.size() - 1;

        while (ind_f < ind_b) {
            int overshoot = -target + numbers[ind_f] + numbers[ind_b];
            if (overshoot == 0) {
                return vector<int> {ind_f + 1, ind_b + 1};
            } else if (overshoot < 0) {
                ind_f++;
            } else {
                ind_b--;
            }
        }
        return vector<int> {};
    }
};
