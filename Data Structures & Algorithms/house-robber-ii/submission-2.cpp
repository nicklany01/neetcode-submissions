class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size() - 1);
        vector<int> dp2(nums.size() - 1);
        if (nums.size() == 1) return nums[0]; 
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);
        for (int i = 2; i < nums.size()-1; i++) {
            dp1[i] = max(dp1[i-1], nums[i] + dp1[i-2]);
        }
        for (int i = 2; i < nums.size()-1; i++) {
            dp2[i] = max(dp2[i-1], nums[i+1] + dp2[i-2]);
        }
        int size = nums.size();
        int max1 = max(dp1[size-1], dp1[size-2]);
        int max2 = max(dp2[size-1], dp2[size-2]);
        cout << max1 << endl;
        cout << max2 << endl;
        return max(max1,max2);
    }
};
