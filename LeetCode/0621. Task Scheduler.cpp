class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> um;
        for (char c : tasks) {
            um[c]++;
        }
        
        int max_repeat = 0;
        for (auto p : um) {
            max_repeat = max(max_repeat, p.second);
        }
        
        int max_task_count = 0;
        for (auto p : um) {
            if (max_repeat == p.second) {
                max_task_count++;
            }
        }
        
        int min_len = (max_repeat - 1) * (1 + n) + max_task_count;
        return max(int(tasks.size()), min_len);
    }
};
