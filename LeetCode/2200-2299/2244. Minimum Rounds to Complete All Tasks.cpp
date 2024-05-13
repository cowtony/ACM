class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> difficulty_count;
        for (int task : tasks) {
            difficulty_count[task]++;
        }

        int round = 0;
        for (auto [difficulty, count] : difficulty_count) {
            if (count == 1) {
                return -1;
            }
            round += (count + 2) / 3;
        }
        return round;
    }
};
