class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s; // Monotonic increase stack.
        int area = 0;
        for (int  i = 0; i < heights.size(); i++) {
            while (!s.empty() and heights[i] < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop(); // Pop here because the index must be the previous element.
                int idx = (s.empty()? -1 : s.top()) + 1;
                area = max(area, height * (i - idx));
            }
            s.push(i);
        }
        return area;
    }
};
