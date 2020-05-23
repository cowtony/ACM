template <class T>
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
    /**
     * @param matrix: a two-dimensional matrix.
     * @param pixelThreshold: the pixel threshold judging high click position.
     * @param areaThreshold: the pixed threshold judging high click area.
     * @return: return the number of high click areas.
     */
    int highClickAreaCount(vector<vector<int>> &matrix, int pixelThreshold, int areaThreshold) {
        #define hash(x, y) (x) * matrix[0].size() + (y)
        UnionFind<int> uf;
        
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                
                if (matrix[r][c] > pixelThreshold) {
                    uf.root(hash(r, c));
                    if (r > 0 and matrix[r - 1][c] > pixelThreshold) {
                        uf.connect(hash(r, c), hash(r - 1, c));
                    }
                    if (c > 0 and matrix[r][c - 1] > pixelThreshold) {
                        uf.connect(hash(r, c), hash(r, c - 1));
                    }
                }
            }
        }
        
        int res = 0;
        for (auto p : uf.roots) {
            if (p.second > areaThreshold) {
                res++;
            }
        }
        
        return res;
        
    }
};
