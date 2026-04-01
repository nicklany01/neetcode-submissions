class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        stack<char> ops;
        int tempNum;
        for (string s : tokens) {
            if (s.size() == 1) {
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
                    default:
                        nums.push(stoi(s));
                }
            } else {
                nums.push(stoi(s));
            }
        }
        return nums.top();
    }
};
