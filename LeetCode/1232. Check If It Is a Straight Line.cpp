class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int u_x = coordinates[1][0] - coordinates[0][0];
        int u_y = coordinates[1][1] - coordinates[0][1];
        for (int i = 2; i < coordinates.size(); i++) {
            int v_x = coordinates[i][0] - coordinates[i - 1][0];
            int v_y = coordinates[i][1] - coordinates[i - 1][1];
            // Cross product.
            if (u_x * v_y - v_x * u_y != 0) {
                return false;
            }
        }
        return true;
    }
};
