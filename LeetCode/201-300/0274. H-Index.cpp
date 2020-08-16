class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> count(citations.size() + 1, 0);
        for (int citation : citations) {
            if (citation >= count.size()) {
                count[count.size() - 1]++;
            } else {
                count[citation]++;
            }
        }
        
        int sum = 0;
        for (int i = count.size() - 1; i >= 0; i--) {
            sum += count[i];
            if (sum < i) {
                continue;
            } else {
                return i;
            }
        }
        return 0;
    }
};
