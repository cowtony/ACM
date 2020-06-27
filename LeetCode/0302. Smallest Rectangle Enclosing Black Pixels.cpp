class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int right = image[0].size() - 1;
        int yy = y;
        while (yy < right) {
            int mid = (yy + right + 1) >> 1;
            if (colHasOne(image, mid)) {
                yy = mid;
            } else {
                right = mid - 1;
            }
        }
        
        int left = 0;
        yy = y;
        while (left < yy) {
            int mid = (left + yy) >> 1;
            if (colHasOne(image, mid)) {
                yy = mid;
            } else {
                left = mid + 1;
            }
        }
        
        int up = 0;
        int xx = x;
        while (up < xx) {
            int mid = (up + xx) >> 1;
            if (rowHasOne(image, mid)) {
                xx = mid;
            } else {
                up = mid + 1;
            }
        }
        
        int down = image.size() - 1;
        xx = x;
        while (xx < down) {
            int mid = (down + xx + 1) >> 1;
            if (rowHasOne(image, mid)) {
                xx = mid;
            } else {
                down = mid - 1;
            }
        }
        
        return (down - up + 1) * (right - left + 1);
    }
    
    bool colHasOne(const vector<vector<char>>& image, int k) {
        for (int i = 0; i < image.size(); i++) {
            if (image[i][k] == '1') {
                return true;
            } 
        }
        return false;
    }
    
    bool rowHasOne(const vector<vector<char>>& image, int k) {
        for (int i = 0; i < image[0].size(); i++) {
            if (image[k][i] == '1') {
                return true;
            } 
        }
        return false;
    }
};
