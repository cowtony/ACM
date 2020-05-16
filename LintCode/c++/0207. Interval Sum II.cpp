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

class Solution {
public:
    /* you may need to use some attributes here */

    /*
    * @param A: An integer array
    */
    Solution(vector<int> A) : arr(A), tree(A) {}

    /*
     * @param start: An integer
     * @param end: An integer
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        return tree.prefixSum(end) - tree.prefixSum(start - 1);
    }

    /*
     * @param index: An integer
     * @param value: An integer
     * @return: nothing
     */
    void modify(int index, int value) {
        int delta = value - arr[index];
        arr[index] = value;
        tree.add(index, delta);
    }
private:
    vector<int> arr;
    BinaryIndexedTree tree;
};
