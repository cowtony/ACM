class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int circumference = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (circumference % 4 != 0) {
            return false;
        }
        
        side_len_ = circumference / 4;
        for (int len : matchsticks) {
            if (len > side_len_) {
                return false;
            }
        }
        used_ = vector<bool>(matchsticks.size(), false);
        matchsticks_ = matchsticks;
        sort(matchsticks_.begin(), matchsticks_.end(), greater<int>());
        
        return dfsGetEdge(4);
    }
    
    bool dfsGetEdge(int edges, int start_idx = 0, int next_idx = 0, int current = 0) {
        if (current == side_len_) {
            if (edges == 1) {
                return true;
            }
            return dfsGetEdge(edges - 1, start_idx + 1);
        }
        if (current > side_len_) {
            return false;
        }
        for (int i = max(start_idx, next_idx); i < used_.size(); i++) {
            if (!used_[i]) {
                used_[i] = true;
                if (dfsGetEdge(edges, start_idx, i + 1, current + matchsticks_[i])) {
                    return true;
                }
                used_[i] = false;
            }
        }
        return false;
    }
    
  private:
    int side_len_;
    vector<bool> used_;
    vector<int> matchsticks_;
};
