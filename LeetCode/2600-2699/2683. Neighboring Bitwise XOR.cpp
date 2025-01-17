class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int result = 0;
        for (int d : derived) {
            result ^= d;
        }
        return result == 0;
    }
};
