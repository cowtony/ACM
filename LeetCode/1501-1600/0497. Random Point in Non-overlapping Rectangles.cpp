class Solution {
public:
    Solution(vector<vector<int>>& rects): rects_(rects) {
        vector<int> areas;
        for (auto rect : rects) {
            areas.push_back((rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
        }
        weights = discrete_distribution<int>(areas.begin(), areas.end());
    }
    
    vector<int> pick() {
        auto& rect = rects_[weights(generator)];
        return {uniform_int_distribution<int>(rect[0], rect[2])(generator), 
                uniform_int_distribution<int>(rect[1], rect[3])(generator)};
    }
    
private:
    vector<vector<int>> rects_;
    default_random_engine generator;
    discrete_distribution<int> weights;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
