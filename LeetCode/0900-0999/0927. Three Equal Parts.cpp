class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> one_pos;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) {
                one_pos.push_back(i);
            }
        }
        if (one_pos.size() % 3 != 0) {
            return {-1, -1};
        }
        if (one_pos.size() == 0) {
            return {0, 2};
        }

        int a = 0;
        int b = one_pos.size() / 3;
        int c = one_pos.size() / 3 * 2;
        for (int i = one_pos[a], j = one_pos[b], k = one_pos[c]; k < arr.size(); i++, j++, k++) {
            if (arr[i] != arr[j] || arr[j] != arr[k]) {
                return {-1, -1};
            }
        }
        int zeros = arr.size() - 1 - one_pos.back();
        return {one_pos[b - 1] + zeros, one_pos[c - 1] + zeros + 1};
    }
};