class Solution {
public:
    int trap(vector<int>& height) {
        // move pointers inwards, smaller one moves inwards, add up empty spaces as you go
        int l = 0, r = height.size() - 1;
        int maxLeft = 0, maxRight = 0, sum = 0;
        while (l < r) {
            maxLeft = max(maxLeft, height[l]);
            maxRight = max(maxRight, height[r]);
            if (height[l] < height[r]) {
                l++;
                sum += max(min(maxLeft, maxRight) - height[l], 0);
                cout << "height[l]: " << height[l] << endl; 
            } else {
                r--;
                sum += max(min(maxLeft, maxRight) - height[r], 0);
                cout << "height[r]: " << height[r] << endl; 
            }
        }
        return sum;
    }
};
