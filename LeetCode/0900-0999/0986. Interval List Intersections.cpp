class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int a = 0, b = 0;
        vector<vector<int>> ans;
        while (a < A.size() and b < B.size()) {
            if (A[a][1] < B[b][0]) {
                a++;
            } else if (A[a][0] > B[b][1]) {
                b++;
            } else {
                ans.push_back({max(A[a][0], B[b][0]), min(A[a][1], B[b][1])});
                if (A[a][1] < B[b][1]) {
                    a++;
                } else {
                    b++;
                }
            }
        }
        return ans;
    }
};
