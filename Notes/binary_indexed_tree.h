// Fenwick Tree
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int size) : bit(size + 1, 0), array(size, 0) {}
    BinaryIndexedTree(const vector<int>& nums) : BinaryIndexedTree(nums.size()) {
        for (int i = 0; i < nums.size(); i++) {
	        bit[i + 1] = array[i] = nums[i];
        }
	    for (int i = 1; i < bit.size(); i++) {
	        int j = i + (i & -i);
            if (j < bit.size()) {
                bit[j] += bit[i];
            }
        }
    }
    void update(int idx, int value) { add(idx, value - array[idx]); }
    void add(int idx, int delta) {
        for (int i = idx + 1; i < bit.size(); i += i & -i) {
            bit[i] += delta;
        }
        array[idx] += delta;
    }
    int prefixSum(int idx) {
        int res = 0;
        for (int i = idx + 1; i > 0; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }
    
private: vector<int> bit, array;
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
