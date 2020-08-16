class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b){
            if (a.at(0) == b.at(0)) {
                return a.at(1) < b.at(1);
            } else {
                return a.at(0) > b.at(0);
            }
        });
        
        vector<vector<int>> res;
        for (const auto& p : people) {
            res.insert(res.begin() + p.at(1), p);
        }
        return res;
    }
};
