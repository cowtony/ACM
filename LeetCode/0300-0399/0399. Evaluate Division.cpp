class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // convert string to index
        int count = 0;
        map<string, int> varToIndex;
        for (const vector<string> &equation : equations) {
            for (const string &var : equation) {
                if (varToIndex.find(var) == varToIndex.end()) {
                    varToIndex[var] = count++;
                }
            }
        }

        // Setup dist matrix
        const double NaN = 1/0.0;
        vector<vector<double>> dist(count, vector<double>(count, NaN));
        for (int i = 0; i < equations.size(); i++) {
            int row = varToIndex.at(equations.at(i).at(0));
            int col = varToIndex.at(equations.at(i).at(1));
            dist[row][col] = values.at(i);
            dist[col][row] = 1.0 / values.at(i);
        }

        // Floyd
        for (int temp = 0; temp < count; temp++) {
            for (int row = 0; row < count; row++) {
                for (int col = 0; col < count; col++) {
                    if (dist[row][temp] != NaN and dist[temp][col] != NaN)
                        dist[row][col] = dist[row][temp] * dist[temp][col];
                }
            }
        }

        // query
        vector<double> ret;
        for (const vector<string> &query : queries) {
            if (varToIndex.find(query.at(0)) == varToIndex.end() or
                varToIndex.find(query.at(1)) == varToIndex.end()) {
                ret.push_back(-1.0);
                continue;
            }

            double val = dist[varToIndex.at(query.at(0))][varToIndex.at(query.at(1))];
            if (val == NaN)
                ret.push_back(-1.0);
            else
                ret.push_back(val);
        }
        return ret;
    }
};
