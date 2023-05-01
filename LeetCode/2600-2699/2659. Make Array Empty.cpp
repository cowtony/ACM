class BinaryIndexedTree {
public:
    BinaryIndexedTree(int size) : bit(size + 1, 0), array(size, 0) {}

    void update(int idx, int value) { 
        add(idx, value - array[idx]);
    }

    void add(int idx, int increment) {
        array[idx] += increment;
        idx++;
        while (idx < bit.size()) {
            bit[idx] += increment;
            idx += idx & -idx;
        }
    }

    int prefixSum(int idx) {
        int res = 0;
        idx++;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    int query(int start, int end) {
        return prefixSum(end) - (start == 0? 0 : prefixSum(start - 1));
    }
    
private:
    std::vector<int> bit, array;
};

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        BinaryIndexedTree bit(nums.size());
        
        map<int, int> val_idx;
        for (int i = 0; i < nums.size(); ++i) {
            val_idx[nums[i]] = i;
            bit.update(i, 1);
        }
        
        auto it = val_idx.begin();
        auto next = it;
        long long result = bit.query(0, it->second);
        // cout << st.query(0, it->second) << endl;
        bit.update(it->second, 0);
        // cout << st.query(0, it->second) << ' ' << result << endl;
        
        for (next++; next != val_idx.end(); it++, next++) {            
            int idx1 = it->second;
            int idx2 = next->second;
            if (idx2 > idx1) {
                result += bit.query(idx1, idx2);
                // cout << idx1 << ' ' << idx2 << ' '<< st.query(idx1, idx2) << ' ' << result << endl;
            } else {
                result += bit.query(idx1, nums.size() - 1) + bit.query(0, idx2);
                // cout << idx1 << ' ' << idx2 << ' '<< st.query(idx1, nums.size() - 1) << ' ' << st.query(0, idx2) << ' ' << result << endl;
            }
            
            bit.update(idx2, 0);
        }
        return result;
    }
};
