class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string> hash_set;
        for (int len = 1; len <= text.length() / 2; len++) {
            int counter = 0;
            for (int l = 0, r = len; r < text.length(); l++, r++) {
                if (text[l] == text[r]) {
                    counter++;
                } else {
                    counter = 0;
                }
                if (counter == len) {
                    hash_set.insert(text.substr(l, len));
                    counter--;
                }
            }
        }
        return hash_set.size();
    }
};
