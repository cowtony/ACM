// LeetCode 84: https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> s; // Monotonic increase stack.
        int area = 0;
        for (int  i = 0; i < height.size(); i++) {
            while (!s.empty() and height[i] < height[s.top()]) {
                int h = height[s.top()];
                s.pop(); // Pop here because the index must be the previous element.
                int idx = (s.empty()? -1 : s.top()) + 1;
                area = max(area, h * (i - idx));
            }
            s.push(i);
        }
        return area;
    }
};
