class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i]) {
                masks[i] |= 1 << (c - 'a');
            }
        }
        
        uint64_t ret = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    ret = max(ret, words[i].length() * words[j].length());
                }
            }
        }
        return ret;
    }
};
