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
    int numIslands(vector<vector<char>>& grid) {
        auto hash = [&grid](int r, int c){ return r * grid[0].size() + c; };
        UnionFind<int> uf;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '0') {
                    continue;
                }
                uf.root(hash(r, c));
                if (r > 0 and grid[r - 1][c] == '1') {
                    uf.connect(hash(r, c), hash(r - 1, c));
                }
                if (c > 0 and grid[r][c - 1] == '1') {
                    uf.connect(hash(r, c), hash(r, c - 1));
                }
            }
        }
        return uf.roots.size();
    }
};

/**** DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == '1')
                {
                    count++;
                    setZero(grid, row, col);
                }
                    
            }
        }
        return count;
    }
    
    void setZero(vector<vector<char>>& grid, const int &row, const int &col) {
        if (grid[row][col] == '1')
        {
            grid[row][col] = '0';
            if (row + 1 < grid.size())
                setZero(grid, row + 1, col);
            if (col + 1 < grid[0].size())
                setZero(grid, row, col + 1);
            if (row - 1 >= 0)
                setZero(grid, row - 1, col);
            if (col - 1 >= 0)
                setZero(grid, row, col - 1);
        }
    }
};
****/
