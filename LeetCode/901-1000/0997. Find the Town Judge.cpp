class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trusted(N + 1, 0);
        vector<bool> trust_other(N + 1, false);
        for (const vector<int>& pair : trust) {
            trust_other[pair.at(0)] = true;
            trusted[pair.at(1)]++;
        }
        
        for (int i = 1; i <= N; i++) {
            if (trusted[i] == N - 1 and trust_other[i] == false) {
                return i;
            }
        }
        return -1;
    }
};
