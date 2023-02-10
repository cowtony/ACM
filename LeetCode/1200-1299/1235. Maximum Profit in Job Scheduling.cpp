class Solution {
public:
    struct Job {
        int start;
        int end;
        int profit;

        bool operator <(const Job& job) const {
            return end < job.end;
        }
    };

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> jobs;
        for (int i = 0; i < profit.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());

        map<int, int> dp = {{0, 0}};
        for (const Job& job : jobs) {
            auto it = prev(dp.upper_bound(job.start));  // Binary search
            dp[job.end] = max(max(dp.rbegin()->second, it->second + job.profit), dp[job.end]);
        }
        return dp.rbegin()->second;
    }
};
