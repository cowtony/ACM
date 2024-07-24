class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int, int> stones;
        for (int pos : nums) {
            stones[pos]++;
        }
        for (int i = 0; i < moveFrom.size(); i++) {
            if (moveTo[i] == moveFrom[i]) {
                continue;
            }
            stones[moveTo[i]] += stones[moveFrom[i]];
            stones.erase(moveFrom[i]);
        }
        vector<int> result;
        for (const auto& [pos, count] : stones) {
            if (count > 0) {
                result.push_back(pos);
            }
        }
        return result;
    }
};
