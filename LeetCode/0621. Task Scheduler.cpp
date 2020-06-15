class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count;
        for (char c : tasks) {
            count[c]++;
        }
        
        int max_repeat = 0;
        for (auto p : count) {
            max_repeat = max(max_repeat, p.second);
        }
        
        int max_task_count = 0;
        for (auto p : count) {
            if (max_repeat == p.second) {
                max_task_count++;
            }
        }
        
        int min_len = (max_repeat - 1) * (1 + n) + max_task_count;
        return max(int(tasks.size()), min_len);
    }
};
