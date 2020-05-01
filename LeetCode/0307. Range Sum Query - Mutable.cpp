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
        idx++;
        while (idx < bit.size()) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }
    
    int prefixSum(int idx) {
        idx++;
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
private:
    vector<int> bit;
};

class NumArray {
public:
    NumArray(vector<int>& nums) : arr(nums), fenwick_tree(nums) {
        
    }
    
    void update(int i, int val) {
        fenwick_tree.add(i, val - arr[i]);
        arr[i] = val;
    }
    
    int sumRange(int i, int j) {
        return fenwick_tree.prefixSum(j) - fenwick_tree.prefixSum(i - 1); 
    }
private:
    vector<int>& arr;
    BinaryIndexedTree fenwick_tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
