// Difficult version of 373.
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        set<vector<int>> visited;
        
        int sum = 0;
        for (auto& row : mat) {
            sum += row[0];
        }
        
        priority_queue<Node> pq;
        pq.push({vector<int>(mat.size(), 0), sum});
        visited.insert(vector<int>(mat.size(), 0));
        for (int i = 1; i < k; i++) {
            Node n = pq.top();
            pq.pop();
            
            for (int i = 0; i < mat.size(); i++) {
                n.idxs[i]++;
                if (visited.find(n.idxs) == visited.end() and n.idxs[i] < mat[i].size()) {
                    visited.insert(n.idxs);
                    pq.push({n.idxs, n.sum - mat[i][n.idxs[i] - 1] + mat[i][n.idxs[i]]});
                }
                n.idxs[i]--;
            }
        }
        return pq.top().sum;
    }
    
private:
    struct Node {
        vector<int> idxs;
        int sum;
        bool operator < (const Node& n) const {
            return sum > n.sum;
        }
    };
};
