class Solution {
public:
    // Find the maximum num of same rows (or flipped rows).
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> count;
        for (auto row : matrix) {
            count[hash(row)]++;
        }
        
        int max_count = 0;
        for (auto [key, value] : count) {
            max_count = max(max_count, value);
        }
        return max_count;
    }

    // Example: Both 001 and 110 will hash to "001".
    string hash(const vector<int>& row) {
        string result = "";
        for (int num : row) {
            result += num == row[0]? '0':'1';
        }
        return result;
    }
};