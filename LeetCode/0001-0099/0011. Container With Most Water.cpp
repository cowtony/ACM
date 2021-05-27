class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_v = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                max_v = max(max_v, min(height[j], height[i]) * (j - i));
            }
        }
        return max_v;
    }
};
