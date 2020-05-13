class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int row = 1; row < triangle.size(); row++) {
            triangle[row][0] += triangle[row - 1][0];
            for (int col = 1; col < row; col++) {
                triangle[row][col] += min(triangle[row - 1][col], triangle[row - 1][col - 1]);
            }
            triangle[row][row] += triangle[row - 1][row - 1];
        }
        int minimum = INT_MAX;
        for (int col = 0; col < triangle.back().size(); col++) {
            minimum = min(minimum, triangle.back().at(col));
        }
        return minimum;
    }
};
