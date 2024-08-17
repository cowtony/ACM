class Solution {
public:
    bool checkRecord(string s) {
        int count_a = 0;
        int count_l = 0;
        for (char c : s) {
            switch (c) {
                case 'A':
                    count_l = 0;
                    if (++count_a >= 2) {
                        return false;
                    }
                    break;
                case 'L':
                    if (++count_l >= 3) {
                        return false;
                    }
                    break;
                case 'P':
                    count_l = 0;
                    break;
                default: return false;
            }
        }
        return true;
    }
};
