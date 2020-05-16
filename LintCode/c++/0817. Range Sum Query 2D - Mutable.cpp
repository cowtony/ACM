class BinaryIndexedTree2D {
public:
    BinaryIndexedTree2D(const vector<vector<int>>& nums) {
        bit = vector<vector<int>>(nums.size() + 1, vector<int>(nums[0].size() + 1, 0));
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                add(i, j, nums[i][j]);
            }
        }
    }
    
    void add(int row, int col, int delta) {
        for (int r = row + 1; r < bit.size(); r += r & -r) {
            for (int c = col + 1; c < bit[0].size(); c += c & -c) {
                bit[r][c] += delta;
            }
        }
    }
    
    int prefixSum(int row, int col) {
        int sum = 0;
        for (int r = row + 1; r > 0; r -= r & -r) {
            for (int c = col + 1; c > 0; c -= c & -c) {
                sum += bit[r][c];
            }
        }
        return sum;
    }
    
private:
    vector<vector<int>> bit;
};

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) : arr(matrix), fenwick_tree(matrix) {}
    
    void update(int row, int col, int val) {
        int delta = val - arr[row][col];
        arr[row][col] = val;
        fenwick_tree.add(row, col, delta);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return fenwick_tree.prefixSum(row2, col2)
               - fenwick_tree.prefixSum(row2, col1 - 1)
               - fenwick_tree.prefixSum(row1 - 1, col2)
               + fenwick_tree.prefixSum(row1 - 1, col1 - 1);
    }
    
private:
    vector<vector<int>> arr;
    BinaryIndexedTree2D fenwick_tree;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
