class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[i].size(); j++) {
                if (land[i][j] == 1) {
                    auto corner = findRightBottom(land, i, j);
                    clearBlock(land, corner);
                    result.push_back(corner);
                }
            }
        }
        return result;
    }

    vector<int> findRightBottom(const vector<vector<int>>& land, int r, int c) {
        int rr = r, cc = c;
        for (; rr < land.size(); rr++) {
            if (rr + 1 >= land.size() || land[rr + 1][cc] == 0) {
                break;
            }
        }
        for (; cc < land[rr].size(); cc++) {
            if (cc + 1 >= land[rr].size() || land[rr][cc + 1] == 0) {
                break;
            }
        }
        return {r, c, rr, cc};
    }

    void clearBlock(vector<vector<int>>& land, const vector<int>& corner) {
        for (int i = corner[0]; i <= corner[2]; i++) {
            for (int j = corner[1]; j <= corner[3]; j++) {
                land[i][j] = 0;
            }
        }
    }
};
