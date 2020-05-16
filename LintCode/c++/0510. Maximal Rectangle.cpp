// LeetCode 85: https://leetcode.com/problems/maximal-rectangle/
class Solution {
public:
    /**
     * @param matrix: a boolean 2D matrix
     * @return: an integer
     */
    int maximalRectangle(vector<vector<bool>> &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int ans = 0;
        vector<int> histogram(matrix[0].size() + 1, 0); // Keep the one extra element to be zero.
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j]) {
                    histogram[j]++;
                } else {
                    histogram[j] = 0;
                }
            }
            ans = max(ans, largestRectangleArea(histogram));
        }
        return ans;
    }
    
    // From LeetCode 84, using monotonic stack.
    int largestRectangleArea(const vector<int>& heights) {
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
