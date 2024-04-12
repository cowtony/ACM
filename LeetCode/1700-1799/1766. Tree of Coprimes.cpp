class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        nums_ = vector<int>(nums.begin(), nums.end());
        children_ = vector<vector<int>>(nums.size());
        for (const auto& edge : edges) {
            children_[edge[0]].push_back(edge[1]);
            children_[edge[1]].push_back(edge[0]);
        }

        preCalculateCoprimes();

        // [value] = stack<depth, node_index>
        vector<stack<pair<int, int>>> nodesForValue(51);
        vector<int> result(nums.size(), -1);
        dfs(0, -1, 0, nodesForValue, result);
        return result;
    }

private:
    void dfs(int node, int parent, int depth, vector<stack<pair<int, int>>>& nodesForValue, vector<int>& result) const {
        int max_depth = -1;
        int max_node = -1;
        for (int coprime : coprimes_[nums_[node]]) {
            if (!nodesForValue[coprime].empty()) {
                auto [d, idx] = nodesForValue[coprime].top();
                if (d > max_depth) {
                    max_depth = d;
                    max_node = idx;
                }
            }
        }
        result[node] = max_node;
        
        nodesForValue[nums_[node]].push({depth, node});
        for (int child : children_[node]) {
            if (child != parent) {
                dfs(child, node, depth + 1, nodesForValue, result);
            }
        }
        nodesForValue[nums_[node]].pop();
    }

    void preCalculateCoprimes() {
        coprimes_ = vector<unordered_set<int>>(51);
        coprimes_[1].insert(1);
        for (int i = 1; i <= 50; i++) {
            for (int j = i + 1; j <= 50; j++) {
                if (gcd(i , j) == 1) {
                    coprimes_[i].insert(j);
                    coprimes_[j].insert(i);
                }
            }
        }
    }
    
    vector<vector<int>> children_;
    vector<unordered_set<int>> coprimes_;
    vector<int> nums_;
};
