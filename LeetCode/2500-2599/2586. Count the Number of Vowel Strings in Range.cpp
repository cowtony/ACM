class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        return count_if(words.begin() + left, words.begin() + right + 1, [this](const string& word) {
            return isVowel(word.front()) && isVowel(word.back());
        });
    }
    
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
