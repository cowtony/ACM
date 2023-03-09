class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count_white = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                count_white++;
            }
        }
        int result = count_white;
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W') {
                count_white++;
            }
            if (blocks[i - k] == 'W') {
                count_white--;
            }
            result = min(result, count_white);
        }
        return result;
    }
};
