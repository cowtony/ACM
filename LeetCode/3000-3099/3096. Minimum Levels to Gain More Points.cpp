class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int total_score = 0;
        for (int point : possible) {
            total_score += point == 1? 1 : -1;
        }
        
        int score = 0;
        for (int i = 0; i < possible.size() - 1; i++) {
            score += possible[i] == 0? - 1 : 1;
            if (score > total_score - score) {
                return i + 1;
            }
        }
        return -1;
    }
};
