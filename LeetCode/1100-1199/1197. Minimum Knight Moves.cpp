// https://leetcode.com/problems/minimum-knight-moves/discuss/682850/C%2B%2B-O(1)-Formula-solution-with-plot-explanation
class Solution {
public:
    int minKnightMoves(int x, int y) {
        // Adjust to 1/8.
        if (x < 0) { x = -x; }
        if (y < 0) { y = -y; }
        if (x < y) { swap(x, y); }
        
        // Corner case.
        if (x == 1 and y == 0) { return 3; }
        if (x == 2 and y == 2) { return 4; }

        // Core formula.
        if (y <= x / 2) {
            return (x + 1) / 2 + (x / 2 - y) % 2; // Lower part.
        } else {
            return (x + y) / 3 + (x + y) % 3; // Higher part.
        }
    }
};
