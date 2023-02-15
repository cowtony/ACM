class Solution {
public:
    int convertTime(string current, string correct) {
        int from = toMinute(current);
        int to = toMinute(correct);
        int count = 0;
        for (int t : {60, 15, 5, 1}) {
            int c = (to - from) / t;
            count += c;
            to -= c * t;
        }
        return count;
    }

    int toMinute(const string& time) {
        return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
    }
};
