class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.length() / rows;
        string result;
        for (int shift = 0; shift <= cols - rows + 1; shift++) {
            for (int r = shift; r < encodedText.length(); r += cols + 1) {
                result += encodedText[r];
            }
        }
        while (result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};
