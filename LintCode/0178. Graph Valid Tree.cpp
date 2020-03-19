class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // Might need to deduplicate edges first.
        if (edges.size() != n - 1) {
            return false; // What if there is duplicated edge?
        }
        count = n;
        father.reserve(n);
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
        for (vector<int> edge : edges) {
            connect(edge[0], edge[1]);
        }
        return count == 1;
    }
    
private:
    int count;
    vector<int> father;
    
    void connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra != rb) {
            father[ra] = rb;
            count--;
        }
    }
    int root(int a) {
        if (father[a] == a) {
            return a;
        } else {
            return father[a] = root(father[a]);
        }
    }
};
