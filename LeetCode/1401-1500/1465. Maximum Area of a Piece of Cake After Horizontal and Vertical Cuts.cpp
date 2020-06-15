class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        horizontalCuts.push_back(h);
        sort(verticalCuts.begin(), verticalCuts.end());
        verticalCuts.push_back(w);
        
        long max_h = horizontalCuts[0], max_v = verticalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            max_h = max(int(max_h), horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i) {
            max_v = max(int(max_v), verticalCuts[i] - verticalCuts[i - 1]);
        }
        
        return (max_h * max_v) % 1000000007;
    }
};
