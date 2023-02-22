class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>> pq;
        for (const auto& c : classes) {
            pq.push({diff(c[0], c[1]), c[0], c[1]});
        }

        while (extraStudents--) {
            auto [_, pass, total] = pq.top();
            pq.pop();
            pq.push({diff(pass + 1, total + 1), pass + 1, total + 1});
        }

        double sum_ratio = 0.0;
        while (!pq.empty()) {
            auto [_, pass, total] = pq.top();
            pq.pop();
            sum_ratio += pass / double(total);
        }

        return sum_ratio / classes.size();
    }

    double diff(double pass, double total) {
        return (pass + 1) / (total + 1) - pass / total;
    }
};
