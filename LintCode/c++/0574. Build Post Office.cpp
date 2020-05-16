class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        vector<int> count_row(grid[0].size(), 0);
        vector<int> count_col(grid.size(), 0);
        for(int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    count_row[c]++;
                    count_col[r]++;
                }
            }
        }
        
        vector<int> cost_row = getCost(count_row);
        vector<int> cost_col = getCost(count_col);
        
        int min_cost = INT_MAX;
        for (int r = 0; r < cost_col.size(); r++) {
            for (int c = 0; c < cost_row.size(); c++) {
                if (grid[r][c] == 0) {
                    min_cost = min(min_cost, abs(cost_col[r]) + abs(cost_row[c]));
                }
            }
        }
        return min_cost;
    }
    
    vector<int> getCost(vector<int> count) {
        vector<int> cost(count.size(), 0);
        int sum = 0;
        for (int i = 0; i < count.size(); i++) {
            cost[0] += count[i] * i;
            sum += count[i];
        }
        int left_sum = count[0];
        for (int i = 1; i < count.size(); i++) {
            cost[i] = cost[i - 1] + left_sum - (sum - left_sum);
            left_sum += count[i];
        }
        return cost;
    }
};
