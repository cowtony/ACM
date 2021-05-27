class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Using bitmask (column 0 is dummy and always 0):
        // 0   1   2   3 | 4   5   6   7 | 8   9   10
        // ------------------------------------------
        // 0   0   0   0 | 1   1   1   1 | 0   0   0   -> 0xF0
        // 0   0   1   1 | 1   1   0   0 | 0   0   0   -> 0x3C
        // 0   0   0   0 | 0   0   1   1 | 1   1   0   -> 0x3C0
        // 0   0   1   1 | 1   1   1   1 | 1   1   0   -> 0x3FC
        
        unordered_map<int, int> um;
        for (auto& reservedSeat : reservedSeats) {
            um[reservedSeat.at(0)] |= 1 << reservedSeat.at(1);
        }

        int res = 2 * n;
        for (auto& p : um) {
            if ((p.second & 0x3FC) == 0) {
                continue;
            } else if ((p.second & 0xF0) == 0 or (p.second & 0x3C) == 0 or (p.second & 0x3C0) == 0) {
                res--;
            } else {
                res -= 2;
            }
            // cout << bitset<11>(p.second) << endl;
        }
        
        return res;
    }
};
