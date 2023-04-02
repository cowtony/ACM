class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<int> diff(reward1.size());
        for (int i = 0; i < diff.size(); ++i) {
            diff[i] = reward1[i] - reward2[i];
        }
        sort(diff.rbegin(), diff.rend());
        return accumulate(diff.begin(), diff.begin() + k, 0) + 
               accumulate(reward2.begin(), reward2.end(), 0);
    }
};
