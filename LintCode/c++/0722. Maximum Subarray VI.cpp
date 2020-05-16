struct TrieNode {
    TrieNode() : sons(2, nullptr) {}
    vector<TrieNode*> sons;
    int value;
    bool is_word = false;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int value) {
        TrieNode* node = root;
        for (int i = kBitLength; i >= 0; i--) {
            int bit = (value >> i) & 1;
            if (node->sons[bit] == nullptr) {
                node->sons[bit] = new TrieNode;
            }
            node = node->sons.at(bit);
        }
        node->value = value;
        node->is_word = true;
    }
    
    int findMaxXorWith(int value) const {
        TrieNode* node = root;
        for (int i = kBitLength; i >= 0; i--) {
            int bit = (value >> i) & 1;
            // Go with the opposite number to get the maximum possible value.
            if (node->sons[1 - bit]) {
                node = node->sons.at(1 - bit);
            } else if (node->sons[bit]) {
                node = node->sons.at(bit);
            }
        }
        return node->value ^ value;
    }
    
private:
    TrieNode* root;
    const int kBitLength = 30;
};

class Solution {
public:
    /**
     * @param nums: the array
     * @return: the max xor sum of the subarray in a given array
     */
    int maxXorSubarray(vector<int> &nums) {
        vector<int> prefix_xor(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefix_xor[i + 1] = prefix_xor[i] ^ nums[i];
        }
        
        Trie trie;
        int max_xor = INT_MIN;
        for (int pre_xor : prefix_xor) {
            trie.insert(pre_xor);
            max_xor = max(max_xor, trie.findMaxXorWith(pre_xor));
        }
        
        return max_xor;
    }
};
