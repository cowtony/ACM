template <class T = int>
class UnionFind {
public:
    // The connect function will add new element automatically.
    void connect(const T& a, const T& b) {
        T ra = root(a);
        T rb = root(b);
        if (ra != rb) {
            roots[rb] += roots[ra];
            father[ra] = rb;
            roots.erase(ra);
        }
    }
    
    // Find root with route compress.
    T root(const T& a) {
        if (father.find(a) == father.end()) { 
            father[a] = a;
            roots[a] = 1;
        }
        if (father[a] == a) { return a; } 
        else { return father[a] = root(father[a]); }
    }
    
    // Store all roots and properties such as size, max_value.
    unordered_map<T, int> roots;
    unordered_map<T, T> father;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind<int> uf;
        for (int i = 0; i < n; i++) {
            uf.root(i);
        }
        for (auto& edge : edges) {
            uf.connect(edge[0], edge[1]);
        }
        return uf.roots.size();
    }
};
