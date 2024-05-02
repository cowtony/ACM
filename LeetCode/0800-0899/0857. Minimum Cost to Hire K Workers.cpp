class Solution {
public:
    struct Worker {
        Worker(int q, int w): quality(q), wage(w) {}

        int quality;
        int wage;

        double getWageToQualityRatio() const {
            return wage / double(quality);
        }

        bool operator <(const Worker& worker) const {
            return getWageToQualityRatio() < worker.getWageToQualityRatio();
        }
    };

    double mincostToHireWorkers(vector<int>& qualities, vector<int>& wages, int k) {
        vector<Worker> workers;
        for (int i = 0; i < qualities.size(); i++) {
            workers.push_back(Worker(qualities[i], wages[i]));
        }
        sort(workers.begin(), workers.end());

        priority_queue<int> quality_pq;  // Store the quality only
        int sum_quality = 0;
        double result = DBL_MAX;
        for (const Worker& worker : workers) {
            sum_quality += worker.quality;
            quality_pq.push(worker.quality);

            if (quality_pq.size() >= k) {
                result = min(result, sum_quality * worker.getWageToQualityRatio());
                sum_quality -= quality_pq.top();
                quality_pq.pop();
            }
        }

        return result;
    }
};
