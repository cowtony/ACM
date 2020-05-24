class Solution {
public:
    int maxVowels(string s, int k) {
        
        int vowel = 0;
        int max_vowel = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                vowel++;
            }
            if (i >= k and isVowel(s[i - k])) {
                vowel--;
            }
            max_vowel = max(max_vowel, vowel);
        }
        return max_vowel;
    }
    
    bool isVowel(char c) {
        return string("aeiou").find(c) != string::npos;
    }
};
