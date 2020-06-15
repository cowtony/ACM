template <class T>
class UnionFind {
public:
    // The connect function will add new element automatically.
    void connect(const T& a, const T& b) {
        T ra = root(a);
        T rb = root(b);
        if (ra != rb) {
            roots[rb] = roots[rb] + roots[ra]; // Change to any operation
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
    /**
     * @param arr: the arr
     * @param k: the k
     * @return: if all instances of value k in arr are connected
     */
    bool judgeConnection(vector<vector<int>> &arr, int k) {
        UnionFind<int> uf;
        auto hash = [&](int r, int c){ return r * arr[0].size() + c; };
        
        for (int r = 0; r < arr.size(); r++) {
            for (int c = 0; c < arr[0].size(); c++) {
                if (arr[r][c] == k) {
                    uf.root(hash(r, c));
                    if (r + 1 < arr.size() and arr[r + 1][c] == k) {
                        uf.connect(hash(r, c), hash(r + 1, c));
                    }
                    if (c + 1 < arr[0].size() and arr[r][c + 1] == k) {
                        uf.connect(hash(r, c), hash(r, c + 1));
                    }
                }
            }
        }
        return uf.roots.size() == 1;
    }
};
