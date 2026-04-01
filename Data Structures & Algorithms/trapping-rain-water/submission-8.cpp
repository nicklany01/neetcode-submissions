class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int lmax = height[l];
        int rmax = height[r];

        int totalWater = 0;
        while (l < r) {
            if (lmax < rmax) {
                l++;
                lmax = max(lmax, height[l]);
                totalWater += max(0, min(lmax, rmax) - height[l]);
            } else {
                r--;
                rmax = max(rmax, height[r]);
                totalWater += max(0, min(lmax, rmax) - height[r]);
            }
        }
        return totalWater;
    }
};
