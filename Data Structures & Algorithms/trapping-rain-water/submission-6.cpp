class Solution {
public:
    int trap(vector<int>& height) {
        deque<int> lmaxall;
        deque<int> rmaxall;
        int lmax = 0;
        int rmax = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            lmax = max(lmax, height[i-1]);
            lmaxall.push_back(lmax);
        }
        for (int i = height.size() - 2; i > 0; i--) {
            rmax = max(rmax, height[i+1]);
            rmaxall.push_front(rmax);
        }
        int totalWater = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            totalWater += max(0, min(lmaxall[i - 1], rmaxall[i - 1]) - height[i]);
        }
        return totalWater;
    }
};
