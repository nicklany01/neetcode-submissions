class KthLargest {
public:
    priority_queue<int> q;
    int k;
    KthLargest(int k_param, vector<int>& nums) {
        k = k_param;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }
    }
    
    int add(int val) {
        q.push(val);
        priority_queue<int> clone = q;
        if (k > q.size()) return -1; 
        for (int i = k - 1; i > 0; i--) {
            clone.pop();
        }
        return clone.top();
    }
};
