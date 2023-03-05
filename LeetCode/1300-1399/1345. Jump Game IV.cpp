class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> idxes;
        for (int i = 0; i < arr.size(); i++) {
            idxes[arr[i]].push_back(i);
        }

        vector<bool> visited(arr.size(), false);
        visited[0] = true;
        queue<pair<int, int>> q;
        int step = 0;
        q.push({0, step});
        
        while (true) {
            auto [idx, step] = q.front();
            q.pop();
            if (idx == arr.size() - 1) {
                return step;
            }

            if (idx > 0 && !visited[idx - 1]) {
                visited[idx - 1] = true;
                q.push({idx - 1, step + 1});
            }
            if (idx + 1 < arr.size() && !visited[idx + 1]) {
                visited[idx + 1] = true;
                q.push({idx + 1, step + 1});
            }
            for (int next : idxes[arr[idx]]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, step + 1});
                }
            }
            idxes.erase(arr[idx]);
        }
    }
};
