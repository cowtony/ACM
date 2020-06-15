/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int res = 0;
        while (res < 6) {
            // 1. Count all the letter occurance at each position.
            vector<vector<int>> count(6, vector<int>(26, 0));
            for (const string& word : wordlist) {
                for (int i = 0; i < 6; i++) {
                    count[i][word[i] - 'a']++;
                }
            }
            
            // 2. Find a word with maximum overlap/count with others.
            int max_score = -1;
            string candidate;
            for (const string& word : wordlist) {
                int score = 0;
                for (int i = 0; i < 6; i++) {
                    score += count[i][word[i] - 'a'];
                }
                if (score > max_score) {
                    max_score = score;
                    candidate = word;
                }
            }
            
            // 3. Guess.
            res = master.guess(candidate);
            
            // 4. Delete all the words that matches with candidate different than result.
            vector<string> new_wordlist;
            for (const string& word : wordlist) {
                int match = 0;
                for (int i = 0; i < 6; i++) {
                    if (word[i] == candidate[i]) {
                        match++;
                    }
                }
                if (match == res) {
                    new_wordlist.push_back(word);
                }
            }
            wordlist = new_wordlist;
        }
    }
};
