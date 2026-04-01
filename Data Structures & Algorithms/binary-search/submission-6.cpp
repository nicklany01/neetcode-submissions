class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        int m = r;
        int c = 0;
        while (true) {
            if (c++ > 10) return -1;
            m = l + (r - l) / 2;
            cout << "m: " << m;
            cout << ", l: " << l;
            cout << ", r: " << r << "\n";
            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target) {
                r = m;
            } else {
                if (l == m) return -1;
                l = m;
            }
        }
        return -1;
    }
};
