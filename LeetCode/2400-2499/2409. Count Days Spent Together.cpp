class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        return max(0, min(toDay(leaveAlice), toDay(leaveBob)) - 
                      max(toDay(arriveAlice), toDay(arriveBob)) + 1);
    }

    int toDay(const string& date) {
        vector<int> days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 1; i < days.size(); i++) {
            days[i] += days[i - 1];
        }

        return days[stoi(date.substr(0, 2)) - 1] + stoi(date.substr(3));
    }
};
