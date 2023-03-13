class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> letter(26, 0);
        for (char c : tiles) {
            letter[c - 'A']++;
        }

        return permutationTiles(letter) - 1; // subtract "" string.
    }

    // Memorization is not necessary since max 7 letters.
    int permutationTiles(vector<int>& letter) {
        int result = 1;
        for (int i = 0; i < 26; ++i) {
            if (letter[i] > 0) {
                letter[i]--;
                result += permutationTiles(letter);
                letter[i]++;
            }
        }
        return result;
    }
};
