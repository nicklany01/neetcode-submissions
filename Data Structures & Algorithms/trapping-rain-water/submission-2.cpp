class Solution {
public:
    int trap(vector<int>& height) {
        deque<int> lmaxall = {0};
        deque<int> rmaxall = {0};
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
        lmaxall.push_back(0);
        rmaxall.push_front(0);
        for (int i = 0; i < lmaxall.size(); i++) {
            cout << lmaxall[i];
        }
        cout << "\n";
        for (int i = 0; i < rmaxall.size(); i++) {
            cout << rmaxall[i];
        }
        cout << "\n";
        int totalWater = 0;
        for (int i = 0; i < height.size(); i++) {
            totalWater += max(0, min(lmaxall[i], rmaxall[i]) - height[i]);
            cout << max(0, min(lmaxall[i], rmaxall[i]) - height[i]);
        }
        return totalWater;
    }
};
