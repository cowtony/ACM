struct Node {
    vector<int>::iterator current;
    vector<int>::const_iterator end;
    
    bool operator < (const Node& n) const {
        return *current > *n.current;
    }
};

class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        priority_queue<Node> pq;
        for (vector<int>& array : arrays) {
            if (!array.empty()) {
                pq.push(Node{array.begin(), array.end()});
            }
        }
        
        vector<int> ret;
        while (!pq.empty()) {
            Node n = pq.top();
            pq.pop();
            ret.push_back(*n.current++);
            if (n.current != n.end) {
                pq.push(n);
            }
        }
        return ret;
    }
};
