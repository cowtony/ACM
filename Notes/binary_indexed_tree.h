// Fenwick Tree
class BinaryIndexedTree {
public:
    BinaryIndexedTree(const vector<int>& nums) : bit(nums.size() + 1, 0) {
        for (int i = 0; i < nums.size(); i++) {
	    bit[i + 1] = nums[i];
        }
	for (int i = 1; i < bit.size(); i++) {
	    int j = i + (i & -i);
            if (j < bit.size()) {
                bit[j] += bit[i];
            }
        }
    }
    
    void add(int idx, int delta) {
        for (int i = idx + 1; i < bit.size(); i += i & -i) {
            bit[i] += delta;
        }
    }
    
    int prefixSum(int idx) {
        int res = 0;
        for (int i = idx + 1; i > 0; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }
private:
    vector<int> bit;
};

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
