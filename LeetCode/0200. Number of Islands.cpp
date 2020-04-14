template <class T>
class UnionFind {
public:
    void add(const T& a) {
        if (father_.find(a) == father_.end()) {
            father_[a] = a;
            count_++;
        }
    }
    
    void connect(const T& a, const T& b) {
        T ra = root(a);
        T rb = root(b);
        if (ra != rb) {
            father_[ra] = rb;
            count_--;
        }
    }
    
    int count() const {
        return count_;
    }
    
private:
    int count_ = 0;
    unordered_map<T, T> father_;
    
    T root(const T& a) {
        if (father_.find(a) == father_.end()) {
            return a;
        }
        if (father_[a] == a) {
            return a;
        } else {
            return father_[a] = root(father_[a]);
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        UnionFind<int> uf;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                uf.add(i * grid[0].size() + j);
                if (i > 0 and grid[i - 1][j] == '1') {
                    uf.connect(i * grid[0].size() + j, (i - 1) * grid[0].size() + j);
                }
                if (j > 0 and grid[i][j - 1] == '1') {
                    uf.connect(i * grid[0].size() + j, i * grid[0].size() + j - 1);
                }
            }
        }
        return uf.count();
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
