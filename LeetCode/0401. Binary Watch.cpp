class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                if (countOne(hour) + countOne(minute) == num) {
                    char s[6];
                    sprintf(s, "%d:%02d", hour, minute);
                    ret.push_back(s);
                }
            }
        }
        return ret;
    }
private:
    int countOne(int num) {
        int count = 0;
        while (num > 0)
        {
            count += num % 2;
            num >>= 1;
        }
        return count;
    }
};
