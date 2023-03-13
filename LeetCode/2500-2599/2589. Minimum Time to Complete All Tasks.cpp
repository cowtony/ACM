class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end());

        int running = 0;
        int i = 0;
        vector<pair<int, int>> running_tasks; // latest_start_time, duration
        while (i < tasks.size() || !running_tasks.empty()) {
            sort(running_tasks.begin(), running_tasks.end());
            int next_task = i < tasks.size()? tasks[i][0] : INT_MAX;
            int next_run = running_tasks.empty()? INT_MAX : running_tasks[0].first;

            if (next_task <= next_run) {
                auto task = tasks[i++];
                running_tasks.push_back({task[1] - task[2] + 1, task[2]});
                continue;
            }

            int duration = running_tasks[0].second;
            running += duration;

            // Run all running tasks for `duration` times.
            vector<pair<int, int>> temp_pq;
            for (auto& [st, dur] : running_tasks) {
                if (dur > duration) {
                    temp_pq.push_back({st + duration, dur - duration});
                }
            }
            running_tasks = temp_pq;

            // Add all possible tasks within range.
            while (i < tasks.size() && tasks[i][0] + 1 <= next_run + duration) {
                auto task = tasks[i++];
                int remaining = task[2] - (next_run + duration - task[0]);
                if (remaining > 0) {
                    running_tasks.push_back({task[1] - remaining + 1, remaining});
                }
            }
        }
        
        return running;
    }
};
