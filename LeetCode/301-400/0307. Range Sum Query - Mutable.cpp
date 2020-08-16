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
    
    void update(int idx, int value) {
        add(idx, value - array[idx]);
    }
    
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
    
private:
    vector<int> bit, array;
};

class NumArray {
public:
    NumArray(vector<int>& nums): fenwick_tree(nums) {
        
    }
    
    void update(int i, int val) {
        fenwick_tree.update(i, val);
    }
    
    int sumRange(int i, int j) {
        return fenwick_tree.prefixSum(j) - fenwick_tree.prefixSum(i - 1); 
    }
private:
    BinaryIndexedTree fenwick_tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
