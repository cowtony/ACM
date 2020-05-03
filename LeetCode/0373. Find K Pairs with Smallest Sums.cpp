class Node {
  public:
    int val;
    int x;
    int y;
    
    bool operator<(const Node& b) const {
        return val > b.val;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() or nums2.empty()) {
            return {};
        }

        // BFS
        priority_queue<Node> pq;
        pq.push({nums1[0] + nums2[0], 0, 0});
        vector<vector<int>> ret;
        while (!pq.empty()) {
            Node node = pq.top();
            pq.pop();
            ret.push_back({nums1[node.x], nums2[node.y]});
            cout << node.x << ' ' << node.y << endl;
            if (ret.size() == k) {
                break;
            }
            
            // Why this x == 0 can be working without dup?
            if (node.x == 0 and node.y + 1 < nums2.size()) {
                pq.push({nums1[node.x] + nums2[node.y + 1], node.x, node.y + 1});
            }
            if (node.x + 1 < nums1.size()) {
                pq.push({nums1[node.x + 1] + nums2[node.y], node.x + 1, node.y});
            }
        }
        return ret;
    }
};
