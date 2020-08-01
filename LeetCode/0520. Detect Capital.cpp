class Solution {
public:
    bool detectCapitalUse(string word) {
        for (int i = 1; i < word.size(); i++) {
            if (islower(word[0]) and isupper(word[i]) 
                or islower(word[1]) != islower(word[i])) {
                return false;
            }
        }
        return true;
    }
};
