class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (string word : words) {
            count[word]++;
        }
        
        struct Node {
            int count = 0;
            string word;
            bool operator < (Node n) const {
                if (count == n.count) {
                    return word < n.word;
                } else {
                    return count > n.count;
                }
            }
        };
        priority_queue<Node> pq;
        for (auto p : count) {
            pq.push(Node{p.second, p.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> ret;
        while (!pq.empty()) {
            ret.insert(ret.begin(), pq.top().word);
            pq.pop();
        }
        return ret;
    }
};
