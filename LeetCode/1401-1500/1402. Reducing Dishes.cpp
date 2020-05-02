class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater());
        
        int coefficient = 0;
        int sum = 0;
        for (int n : satisfaction) {
            sum += n;
            if (sum < 0) {
                break;
            }
            coefficient += sum;
        }
        return coefficient;
    }
};
