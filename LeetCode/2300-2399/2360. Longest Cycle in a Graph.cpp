class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int result = -1;
        vector<int> steps(edges.size(), 0);
        for (int node = 0, step = 1; node < edges.size(); ++node) {
            int n = node, init_step = step;
            while (n != -1 && steps[n] == 0) {
                steps[n] = step++;
                n = edges[n];
            }
            if (n != -1 && steps[n] >= init_step) {
                result = max(result, step - steps[n]);
            }
        }
        return result;
    }
};
