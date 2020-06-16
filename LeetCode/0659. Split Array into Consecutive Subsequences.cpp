class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // Key: last value, Value: number of this chain.
        unordered_map<int, int> chain_1;
        unordered_map<int, int> chain_2;
        unordered_map<int, int> chain_3;
        
        for (int num : nums) {
            if (chain_1[num - 1] > 0) {
                chain_1[num - 1]--;
                chain_2[num]++;
            } else if (chain_2[num - 1] > 0) {
                chain_2[num - 1]--;
                chain_3[num]++;
            } else if (chain_3[num - 1] > 0) {
                chain_3[num - 1]--;
                chain_3[num]++;
            } else {
                chain_1[num]++;
            }
        }
        
        for (auto p : chain_1) {
            if (p.second > 0) {
                return false;
            }
        }
        for (auto p : chain_2) {
            if (p.second > 0) {
                return false;
            }
        }
        
        return true;
    }
};
