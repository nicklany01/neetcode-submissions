class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> elements;
        // keep adding different choices of numbers
        // false condition when it hits sum > target
        function<void(int,int)> backtrack = [&](int index, int sum) {
            // base case(s)
            if (sum > target) {
                // no point going further if we've already gone over
                return;
            } else if (sum == target) {
                // if we've hit the target, add to the result
                result.push_back(elements);
                return;
            }
            // i = index prevents combinations of 2,3 and then 3,2
            for (int i = index; i < nums.size(); i++) {
                // base case(s)
                if (sum > target) {
                    // no point going further if we've already gone over
                    return;
                } else if (sum == target) {
                    // if we've hit the target, add to the result
                    result.push_back(elements);
                    return;
                }
                int num = nums[i];
                // decision 1: check with the same number
                elements.push_back(num);
                backtrack(i, sum + num);
                elements.pop_back();
            }
        };
        backtrack(0, 0);
        return result;
    }
};
