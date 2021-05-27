class Solution {
public:
    int maxScore(string s) {
        int score = 0;
        for (char c : s) {
            if (c == '1') {
                score++;
            }
        }
        
        int max_score = 0;
        for (char c : s.substr(0, s.length() - 1)) {
            if (c == '0') {
                score++;
            } else {
                score--;
            }
            max_score = max(max_score, score);
        }
        
        return max_score;
    }
};
