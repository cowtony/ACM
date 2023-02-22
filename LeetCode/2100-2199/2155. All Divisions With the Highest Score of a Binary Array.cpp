class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        // Start from empty left.
        int score = accumulate(nums.begin(), nums.end(), 0);  // Number of 1s for 'right' section.
        int max_score = score;
        vector<int> result = {0};

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                score++;
            } else {
                score--;
            }
            
            if (score > max_score) {
                max_score = score;
                result = {i + 1};
            } else if (score == max_score) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
