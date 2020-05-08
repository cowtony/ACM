class Solution {
public:
    /**
     * @param push: the array push
     * @param pop: the array pop
     * @return: return whether there are legal sequences
     */
    bool isLegalSeq(vector<int> &push, vector<int> &pop) {
        int i = 0;
        stack<int> s;
        for (int num : push) {
            s.push(num);
            while (!s.empty() and s.top() == pop[i]) {
                i++;
                s.pop();
            }
        }
        return s.empty();
    }
};
