class Solution {
public:
    /**
     * @param ambigram: A list of paired ambigram letter.
     * @param word: A string need to be judged.
     * @return: If it is special palindrome string, return true.
     */
     

    bool ispalindrome(vector<string> &ambigram, string &word) {
        vector<long> m(256, 0);
        for (char c = 'a'; c <= 'z'; c++) {
            m[c] = 1 << (c - 'a');
        }
        for (const string& s : ambigram) {
            m[s.at(0)] |= 1 << (s.at(1) - 'a');
            m[s.at(1)] |= 1 << (s.at(0) - 'a');
        }
        
        for (int i = 0, j = word.length() - 1; i < j; i++, j--) {
            if ((m[word[i]] & m[word[j]]) == 0) {
                return false;
            }
        }
        return true;
    }
};
