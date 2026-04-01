class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int min = r;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] > nums[min]) {
                l = m + 1;
            } else {
                r = m - 1;
                min = m;
            }
        }
        int offset = min;
        l = 0;
        r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            cout << nums[(m + offset) % n] << "\n";
            if (nums[(m + offset) % n] == target) return (m + offset) % n;
            if (nums[(m + offset) % n] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }
};
