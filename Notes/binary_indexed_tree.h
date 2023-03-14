// Fenwick Tree
class BinaryIndexedTree {
  public:
    BinaryIndexedTree(int size) : bit(size, 0), array(size, 0) {}

    void update(int idx, int value) { 
        add(idx, value - array[idx]);
    }

    void add(int idx, int increment) {
        array[idx] += increment;
        while (idx < bit.size()) {
            bit[idx] += increment;
            idx += idx & -idx;
        }
    }

    int prefixSum(int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
    
  private:
    vector<int> bit, array;
};

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
