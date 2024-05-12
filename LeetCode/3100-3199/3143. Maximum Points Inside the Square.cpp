class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<int> min_diameter(26, INT_MAX);
        int min_invalid_diameter = INT_MAX;
        for (int i = 0; i < points.size(); i++) {
            int d = diameter(points[i][0], points[i][1]);
            
            min_invalid_diameter = min(min_invalid_diameter, max(d, min_diameter[s[i] - 'a']));
            min_diameter[s[i] - 'a'] = min(d, min_diameter[s[i] - 'a']);
        }

        return count_if(min_diameter.begin(), min_diameter.end(), [min_invalid_diameter](int diameter) {
            return diameter < min_invalid_diameter;
        });
    }
    
    int diameter(int x, int y) {
        return max(abs(x), abs(y));
    }
};
