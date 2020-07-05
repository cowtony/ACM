class BinaryIndexedTree2D {
public:
    BinaryIndexedTree2D(int row, int col): bit(row + 1, vector<int>(col + 1, 0)), array(row, vector<int>(col, 0)) {}
    
    void update(int row, int col, int value) {
        add(row, col, value - array[row][col]);
    }
    
    void add(int row, int col, int delta) {
        for (int r = row + 1; r < bit.size(); r += r & -r) {
            for (int c = col + 1; c < bit[0].size(); c += c & -c) {
                bit[r][c] += delta;
            }
        }
        array[row][col] += delta;
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
    vector<vector<int>> bit, array;
};

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) : fenwick_tree(matrix.size(), matrix.empty()? 0 : matrix[0].size()) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                fenwick_tree.add(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        fenwick_tree.update(row, col, val);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return fenwick_tree.prefixSum(row2, col2)
            + fenwick_tree.prefixSum(row1 - 1, col1 - 1)
            - fenwick_tree.prefixSum(row1 - 1, col2) 
            - fenwick_tree.prefixSum(row2, col1 - 1);
    }
    
private:
    BinaryIndexedTree2D fenwick_tree;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
