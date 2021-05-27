class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int len = 0;
        for (int d : data) {
            if (len == 0) {
                len = header(d);
            } else {
                len--;
                if ((d >> 6) ^ 0b10) {
                    return false;
                }
            }
        }
        return len == 0;
    }
    
    int header(uint8_t byte) {
        if (byte >> 3 == 0b11110) {
            return 3;
        } else if (byte >> 4 == 0b1110) {
            return 2;
        } else if (byte >> 5 == 0b110) {
            return 1;
        } else if (byte >> 7 == 0) {
            return 0;
        } else {
            return -1;
        }
    }
};
