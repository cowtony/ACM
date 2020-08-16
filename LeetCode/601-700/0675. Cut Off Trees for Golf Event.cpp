class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        priority_queue<Node> pq;
        for (int r = 0; r < forest.size(); r++) {
            for (int c = 0; c < forest[0].size(); c++) {
                if (forest[r][c] > 1) {
                    pq.push({forest[r][c], r, c});
                }
            }
        }
        
        int total_dist = 0;
        Node start{0, 0, 0};
        while (!pq.empty()) {
            Node to = pq.top();
            pq.pop();
        
            int dist = bfsDist(forest, start, to);
            if (dist == -1) {
                return -1;
            }
            total_dist += dist;
            start = to;
        }

        return total_dist;
    }
    
private:
    struct Node {
        int height;
        int r;
        int c;
        int length;
        bool operator < (Node n) const {
            return n.height < height;
        }
    };
    
    const vector<int> kX = {0, 0, 1, -1};
    const vector<int> kY = {1, -1, 0, 0};
    
    int bfsDist(vector<vector<int>> forest, Node from, Node to) {
        if (from.r == to.r and from.c == to.c) {
            return 0;
        }
        queue<Node> q;
        from.length = 0;
        q.push(from);
        forest[from.r][from.c] = 0;
        while (!q.empty()) {
            Node n = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int r = n.r + kX.at(i);
                int c = n.c + kY.at(i);
                
                if (r < 0 or r >= forest.size() or c < 0 or c >= forest[0].size()) {
                    continue;
                }
                if (r == to.r and c == to.c) {
                    return n.length + 1;
                } 
                if (forest[r][c] > 0) {
                    q.push({forest[r][c], r, c, n.length + 1});
                    forest[r][c] = 0;
                }
            }
        }
        return -1;
    }
};
