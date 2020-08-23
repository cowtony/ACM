class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int start = rounds.front(), end = rounds.back();
        
        vector<int> res;
        if (end >= start) {
            for (int i = start; i <= end; i++) {
                res.push_back(i);
            }
        } else {
            for (int i = 1; i <= end; i++) {
                res.push_back(i);
            }
            for (int i = start; i <= n; i++) {
                res.push_back(i);
            }
        }
        return res;
    }
};
