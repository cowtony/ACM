class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1;
        int max_score = 0, score = 0;
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left++];
                score++;
            } else if (score > 0) {
                power += tokens[right--];
                score--;
            } else {
                left++;
            }
            max_score = max(max_score, score);
        }
        return max_score;
    }
};
