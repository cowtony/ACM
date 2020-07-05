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

class Solution {
public:
    string minInteger(string num, int k) {
        vector<deque<int>> indexs(10);
        for (int i = 0; i < num.size(); i++) {
            indexs[num[i] - '0'].push_back(i);
        }
        
        BinaryIndexedTree bit(num.size());
        
        string res;
        while (res.size() < num.size()) {
            for (int digit = 0; digit <= 9; digit++) {
                if (indexs[digit].empty()) {
                    continue;
                }
                int idx = indexs[digit].front();
                int move = idx - bit.prefixSum(idx);
                if (move <= k) {
                    k -= move;
                    res.push_back('0' + digit);
                    bit.add(idx, 1);
                    indexs[digit].pop_front();
                    break;
                }
            }
        }
        return res;
    }
};
