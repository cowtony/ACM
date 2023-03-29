class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        
        int coefficient = 0;
        int sum = 0;
        for (int s : satisfaction) {
            sum += s;
            if (sum < 0) {
                break;
            }
            coefficient += sum;
        }
        return coefficient;
    }
};
