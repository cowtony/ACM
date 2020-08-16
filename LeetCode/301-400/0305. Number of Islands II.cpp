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
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        auto hash = [n](int r, int c){ return r * n + c; };
        vector<int> kX = {0, 0, 1, -1};
        vector<int> kY = {1, -1, 0, 0};
        
        vector<int> res;
        UnionFind<int> uf;
        
        for (auto& pos : positions) {
            uf.root(hash(pos[0], pos[1]));
            for (int i = 0; i < 4; i++) {
                int r = pos[0] + kX[i];
                int c = pos[1] + kY[i];
                if (r < 0 or r >= m or c < 0 or c >= n) {
                    continue;
                }
                if (uf.father.find(hash(r, c)) != uf.father.end()) {
                    uf.connect(hash(r, c), hash(pos[0], pos[1]));
                }
            }
            res.push_back(uf.roots.size());
        }
        
        return res;
    }
};
