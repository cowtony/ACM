class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // Find closest point in rectangle to circle center.
        int dx = max(x1, min(x_center, x2));
        int dy = max(y1, min(y_center, y2));
        // Compare to center distance.
        return ((x_center - dx) * (x_center - dx) + (y_center - dy) * (y_center - dy)) <= (radius * radius);
    }
};
