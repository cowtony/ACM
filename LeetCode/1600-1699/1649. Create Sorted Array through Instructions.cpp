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

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        BinaryIndexedTree bit(1E5 + 1);
        int cost = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            cost = (cost + min(bit.prefixSum(instructions[i] - 1), i - bit.prefixSum(instructions[i]))) % 1000000007;
            bit.add(instructions[i], 1);
        }
        return cost;
    }
};
