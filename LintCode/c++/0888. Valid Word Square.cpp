class Solution {
public:
    /**
     * @param words: a list of string
     * @return: a boolean
     */
    bool validWordSquare(vector<string> &words) {
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words[0].length(); j++) {
                if (words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
