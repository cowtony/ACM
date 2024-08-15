class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> count(3, 0);
        for (int bill : bills) {
            switch (bill) {
                case 5:
                    count[0]++;
                    break;
                case 10:
                    count[1]++;
                    if (--count[0] < 0) {
                        return false;
                    }
                    break;
                case 20:
                    count[2]++;
                    if (count[1] > 0) {
                        count[1]--;
                        if (--count[0] < 0) {
                            return false;
                        }
                    } else {
                        count[0] -= 3;
                        if (count[0] < 0) {
                            return false;
                        }
                    }
                    break;
                default: return false;
            }
        }
        return true;
    }
};
