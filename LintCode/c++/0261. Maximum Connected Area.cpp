class UnionFind {
public:
    UnionFind(int n) : father(n), data(n, 1) {
        for (int i = 0; i < father.size(); i++) {
            father[i] = i;
        }
        count = n;
    }
    void connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra != rb) {
            father[ra] = rb;
            data[rb] += data[ra];
            count--;
        }
    }
    int root(int a) {
        if (father[a] == a) { return a; } 
        else { return father[a] = root(father[a]); }
    }
    
    int count;
    vector<int> father;
    vector<int> data;
};

class Solution {
public:
    /**
     * @param matrix: the matrix for calculation.
     * @return: return the max area after operation at most once.
     */
    int maxArea(vector<vector<int>> &matrix) {
        int max_area = 0;
        UnionFind uf(matrix.size() * matrix[0].size());
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                int hash_pos = r * matrix[0].size() + c;
                if (matrix[r][c] == 1) {
                    
                    if (r > 0 and matrix[r - 1][c] == 1) {
                        uf.connect(hash_pos, (r - 1) * matrix[0].size() + c);
                    }
                    if (c > 0 and matrix[r][c - 1] == 1) {
                        uf.connect(hash_pos, r * matrix[0].size() + c - 1);
                    }
                }
                max_area = max(max_area, uf.data[uf.root(hash_pos)]);
            }
        }
        
        const vector<int> kX = {0, 0, 1, -1};
        const vector<int> kY = {1, -1, 0, 0};
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                if (matrix[r][c] == 0) {
                    unordered_set<int> roots;
                    for (int i = 0; i < 4; i++) {
                        int x = r + kX.at(i);
                        int y = c + kY.at(i);
                        if (x < 0 or x >= matrix.size() or y < 0 or y >= matrix[0].size()) {
                            continue;
                        }
                        if (matrix[x][y] == 1) {
                            roots.insert(uf.root(x * matrix[0].size() + y));
                        }
                    }
                    int area = 1;
                    for (int root : roots) {
                        area += uf.data[root];
                    }
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};
