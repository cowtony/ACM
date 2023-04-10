class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0;
        const vector<int> kMove{1, 0, -1, 0, 1};
        for (char c : instructions) {
            if (c == 'G') {
                x += kMove[dir];
                y += kMove[dir + 1];
            } else if (c == 'L') {
                dir = (dir + 3) % 4;
            } else { // c == 'R'
                dir = (dir + 1) % 4;
            }
        }
        return x == 0 && y == 0 || dir != 0;
    }
};
