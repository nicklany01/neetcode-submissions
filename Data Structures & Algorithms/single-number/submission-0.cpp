class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num : nums) {
            if (s.contains(num)) s.erase(num);
            else s.insert(num);
        }
        auto it = s.begin();
        return *it;
    }
};
