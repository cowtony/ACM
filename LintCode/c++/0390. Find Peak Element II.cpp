class Solution {
public:
    /*
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> &A) {
        return findCol(A, 0, 0, A.size() - 1, A[0].size() - 1);
    }
    
    vector<int> findRow(vector<vector<int>> &A, int x1, int y1, int x2, int y2)
    {
        int mid = (x1 + x2) / 2;
        
        int m = -1;
        int index = -1;
        // 在 mid 这一行去找最大值
        for (int i = y1; i <= y2; ++i)
            if (A[mid][i] > m)
            {
                m = A[mid][i];
                index = i;
            }

        if (A[mid][index] < A[mid - 1][index]) {
            return findCol(A, x1, y1, mid - 1, y2);
        }
        if (A[mid][index] < A[mid + 1][index]) {
            return findCol(A, mid + 1, y1, x2, y2);
        }
        return {mid, index};
    }
    
    vector<int> findCol(vector<vector<int>> &A, int x1, int y1, int x2, int y2) {
        int mid = (y1 + y2) / 2;
            
        int m = -1;
        int index = -1;
        // 找到这一列的最大值
        for (int i = x1; i <= x2; ++i)
            if (A[i][mid] > m)
            {
                m = A[i][mid];
                index = i;
            }

        if (A[index][mid] < A[index][mid - 1]) {
            return findRow(A, x1, y1, x2, mid - 1);
        }
        if (A[index][mid] < A[index][mid + 1]) {
            return findRow(A, x1, mid + 1, x2, y2);
        }
        return {index, mid};
    }
};
