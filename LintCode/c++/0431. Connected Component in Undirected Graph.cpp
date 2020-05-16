/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
template <class T>
class UnionFind {
public:
    // The connect function will add new element automatically.
    void connect(const T& a, const T& b) {
        T ra = root(a);
        T rb = root(b);
        if (ra != rb) {
            father[ra] = rb;
            count_--;
        }
    }
    
    // Find root with route compress.
    T root(const T& a) {
        if (father.find(a) == father.end()) { 
            father[a] = a;
            count_++;
            return a;
        }
        if (father[a] == a) { return a; } 
        else { return father[a] = root(father[a]); }
    }
    
    // Get number of blocks.
    int count() const { return count_; }
    unordered_map<T, T> father;
private:
    int count_ = 0;
};


class Solution {
public:
    /*
     * @param nodes: a array of Directed graph node
     * @return: a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*> nodes) {
        for (DirectedGraphNode* node : nodes) {
            dfs(node);
        }
        
        map<int, set<int>> m;
        for (auto p : union_find.father) {
            m[union_find.root(p.first)].insert(p.first);
        }
        
        vector<vector<int>> ret;
        for (auto p : m) {
            ret.push_back({p.second.begin(), p.second.end()});
        }
        return ret;
    }
    
    UnionFind<int> union_find;
    void dfs(DirectedGraphNode* node) {
        if (!node) {
            return;
        }
        union_find.root(node->label);
        for (DirectedGraphNode* neighbor : node->neighbors) {
            union_find.connect(node->label, neighbor->label);
            // dfs(neighbor);
        }
    }
};
