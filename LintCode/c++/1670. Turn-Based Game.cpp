class Solution {
public:
    /**
     * @param atk: the atk of monsters
     * @return: Output the minimal damage QW will suffer
     */
    long long getAns(vector<int> &atk) {
        sort(atk.begin(), atk.end());
        long long prefix_sum = 0;
        long long res = 0;
        for (int i = 0; i < atk.size() - 1; i++) {
            prefix_sum += atk[i];
            res += prefix_sum;
        }
        return res;
    }
};
