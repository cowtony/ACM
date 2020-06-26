class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        vector<int> board_1d; // -1: not visited,
        for (int row = N - 1; row >= 0; row--) {
            if ((N - row) % 2 == 1) {
                for (int col = 0; col < N; col++) {
                    board_1d.push_back(board[row][col]);
                }
            } else {
                for (int col = N - 1; col >= 0; col--) {
                    board_1d.push_back(board[row][col]);
                }
            }
        }
        
        vector<bool> visited(board_1d.size(), false);
        visited[0] = true;
        int step = 0;
        queue<int> q;
        q.push(1);
        q.push(-1);
        while (!q.empty()) {
            int pos = q.front();
            q.pop();

            if (pos == N * N) {
                return step;
            }
            if (pos == -1) {
                step++;
                q.push(-1);
                if (q.front() == -1) {
                    break;
                }
                continue;
            }
            for (int i = 1; i <= 6; i++) {
                if (pos + i - 1 >= board_1d.size()) {
                    break;
                }
                
                int p = pos + i;
                if (board_1d[p - 1] != -1) {
                    p = board_1d[p - 1];
                }
                if (!visited[p - 1]) {
                    visited[p - 1] = true;
                    q.push(p);
                }
            }
        }
        
        return -1;
    }
};
