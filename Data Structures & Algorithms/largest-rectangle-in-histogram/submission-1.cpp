class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // if height goes down, we need to check the previous height thats at that size to see if area of lower height is better
        // if height goes up, no idea
        stack<pair<int,int>> s;
        s.push({0, 0});
        int maxArea = heights[0];
        for (int i = 0; i < heights.size(); i++) {
            // if it steps down, keep popping checking all the rectangles formed until heights[i] >= s.top()
            int lastIndex = i;
            while (heights[i] < s.top().second) {
                lastIndex = s.top().first; // next s.top() will start here cos it was larger
                maxArea = max(maxArea, (i - s.top().first) * s.top().second);
                s.pop();
            }
            // if it steps up, update top
            if (heights[i] > s.top().second) {
                s.push({lastIndex, heights[i]});
                cout << "index: " << s.top().first << ", height:" << s.top().second << endl;
            }
        }
        while (!s.empty()) {
            cout << "index: " << s.top().first << ", height:" << s.top().second << endl;
            maxArea = max(maxArea, ((int)heights.size() - s.top().first) * s.top().second);
            cout << ((int)heights.size() - s.top().first) * s.top().second;
            s.pop();
        }
        return maxArea;

    }
};
