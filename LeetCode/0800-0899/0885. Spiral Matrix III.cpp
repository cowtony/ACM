class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result = {{rStart, cStart}};

        const vector<int> kMove = {0, 1, 0, -1, 0};
        int direction = 0;
        int r = rStart, c = cStart;
        int n = 0;

        while (result.size() < rows * cols) {
            int edge = n++ / 2 + 1;  // The edge length increases: 1, 1, 2, 2, 3, 3, 4, 4, ...
            while (edge--) {  
                r += kMove[direction];
                c += kMove[direction + 1];
                if (0 <= r && r < rows && 0 <= c && c < cols) {
                    result.push_back({r, c});
                }
            }
            direction = (direction + 1) % 4;
        }

        return result;
    }
};
