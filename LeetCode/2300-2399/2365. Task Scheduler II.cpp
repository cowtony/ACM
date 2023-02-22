class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long days = 0;
        unordered_map<int, long long> m;
        for (int i = 0; i < tasks.size(); i++, days++) {
            if (m.find(tasks[i]) != m.end() && days - m[tasks[i]] <= space) {
                days = space + 1 + m[tasks[i]];
            }
            m[tasks[i]] = days;
        }
        return days;
    }
};
