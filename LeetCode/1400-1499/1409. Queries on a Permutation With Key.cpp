class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> idx(m + 1);
        for (int i = 1; i <= m; i++) {
            idx[i] = i - 1;
        }
        
        vector<int> ret;
        for (int query : queries) {
            for (int i = 1; i <= m; i++) {
                if (idx[i] < idx[query]) {
                    idx[i]++;
                }
            }
            ret.push_back(idx[query]);
            idx[query] = 0;
        }
        return ret;
    }
};
