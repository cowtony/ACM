class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shifts) {
        int move_left = 0;
        for (vector<int> shift : shifts) {
            if (shift[0] == 0) {
                move_left = (move_left + shift[1] + s.length()) % s.length();
            } else {
                move_left = (move_left - shift[1] + s.length()) % s.length();
            }
        }
        return s.substr(move_left) + s.substr(0, move_left);
    }
};
