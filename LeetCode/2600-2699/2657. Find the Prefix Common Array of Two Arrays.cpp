class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> result(A.size(), 0);
        vector<int> visited(A.size() + 1, 0);
        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            if (++visited[A[i]] == 2) {
                count++;
            }
            if (++visited[B[i]] == 2) {
                count++;
            }
            result[i] = count;
        }
        return result;
    }
};
