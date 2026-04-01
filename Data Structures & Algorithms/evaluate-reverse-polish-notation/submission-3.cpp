class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        stack<char> ops;
        int tempNum;
        for (string s : tokens) {
            if (s.back() >= '0' && s.back() <= '9') {
                nums.push(stoi(s));
            } else {
                switch (s[0]) {
                    case '+':
                        tempNum = nums.top();
                        nums.pop();
                        nums.top() = nums.top() + tempNum; 
                        break;
                    case '-':
                        tempNum = nums.top();
                        nums.pop();
                        nums.top() = nums.top() - tempNum; 
                        break;
                    case '*':
                        tempNum = nums.top();
                        nums.pop();
                        nums.top() = nums.top() * tempNum; 
                        break;
                    case '/':
                        tempNum = nums.top();
                        nums.pop();
                        nums.top() = nums.top() / tempNum; 
                        break;
                }
            }
        }
        return nums.top();
    }
};
