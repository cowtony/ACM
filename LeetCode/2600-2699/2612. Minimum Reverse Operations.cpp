class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> result(n, -1);
        queue<pair<int, int>> q;
        q.push({p, 0});
        result[p] = 0;
        
        set<int> even, odd;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                even.insert(i);
            } else {
                odd.insert(i);
            }
        }
        for (int ban_idx : banned) {
            if (ban_idx % 2 == 0) {
                even.erase(ban_idx);
            } else {
                odd.erase(ban_idx);
            }
        }
        even.erase(p);
        odd.erase(p);
        
        while (!q.empty()) {
            auto [idx, step] = q.front();
            q.pop();

            int low = 2 * max(idx, k - 1) - idx - (k - 1);
            int high = 2 * min(idx, n - k) - idx + (k - 1);
            auto& avaliable_idxes = (k % 2 == 1) ^ (idx % 2 == 1)? even : odd;
            for (auto it = avaliable_idxes.lower_bound(low); it != avaliable_idxes.end() && *it <= high; it = avaliable_idxes.erase(it)) {
                q.push({*it, step + 1});
                result[*it] = step + 1;
            }
        }
        return result;
    }
};
