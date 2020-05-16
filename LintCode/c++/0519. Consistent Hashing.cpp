class Solution {
public:
    /*
     * @param n: a positive integer
     * @return: n x 3 matrix
     */
    vector<vector<int>> consistentHashing(int n) {
        vector<vector<int>> ans;
        ans.emplace_back(vector<int>({0, 359, 1}));
        for (int i = 2; i <= n; i++) {
            vector<int> max_range = {0, 0, 0};
            int max_idx = -1;
            for (int j = 0; j < i - 1; j++) {
                if (max_range[1] - max_range[0] < ans[j][1] - ans[j][0] or max_range[1] - max_range[0] == ans[j][1] - ans[j][0] and max_range[2] > ans[j][2]) {
                    max_range = ans[j];
                    max_idx = j;
                }
            }
            
            ans.insert(ans.begin() + max_idx + 1, ans[max_idx]);
            ans[max_idx][1] = (ans[max_idx][0] + ans[max_idx][1]) / 2;
            ans[max_idx + 1][0] = (ans[max_idx + 1][0] + ans[max_idx + 1][1]) / 2 + 1;
            ans[max_idx + 1][2] = i;
        }
        return ans;
    }
};
