class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) {
            return false;
        }
        
        const unordered_set<char> kVowels = {'a', 'e', 'i', 'o', 'u'};
        bool is_vowel = false, is_consonant = false;
        for (char c : word) {
            if (isalpha(c)) {
                if (kVowels.find(tolower(c)) != kVowels.end()) {
                    is_vowel = true;
                } else {
                    is_consonant = true;
                }
            } else if (!isdigit(c)) {
                return false;
            }
        }
        return is_vowel && is_consonant;
    }
};
