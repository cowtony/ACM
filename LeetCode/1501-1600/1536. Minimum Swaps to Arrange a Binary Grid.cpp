class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> zeros;
        for (int row = 0; row < grid.size(); row++) {
            int i = grid[row].size() - 1;
            for (; i >= 0 and grid[row][i] == 0; i--) {;}
            zeros.push_back(max(i, 0));
        }
        
        int res = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int i = row; i < zeros.size(); i++) {
                if (zeros[i] <= row) {
                    res += i - row;
                    zeros.insert(zeros.begin(), zeros[i]);
                    zeros.erase(zeros.begin() + i + 1);
                    goto next;
                }
            }
            return -1;
            next:;
        }
        return res;
    }
};
