class Solution {
public:
    string maximumBinaryString(string binary) {
        // 00 -> 10
        // 010 -> 101
        // 0110 -> 0101 -> 0011 -> 1011
        // 01110 -> 10111

        string result(binary.length(), '1');
        int zero_idx = -1;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '0') {
                if (zero_idx == -1) {
                    zero_idx = i;
                } else {
                    zero_idx++;
                }
            }
        }
        if (zero_idx >= 0) {
            result[zero_idx] = '0';
        }
        return result;
    }
};
