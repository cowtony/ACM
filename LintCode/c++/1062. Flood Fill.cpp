class Solution {
public:
    /**
     * @param image: a 2-D array
     * @param sr: an integer
     * @param sc: an integer
     * @param newColor: an integer
     * @return: the modified image
     */
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int current = image.at(sr).at(sc);
        if (current == newColor) {
            return image;
        }
        image[sr][sc] = newColor;
        static const vector<int> kX = {0, 0, 1, -1};
        static const vector<int> kY = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int r = sr + kX.at(i);
            int c = sc + kY.at(i);
            if (r < 0 or r >= image.size() or c < 0 or c >= image.at(0).size()) {
                continue;
            }
            if (image.at(r).at(c) == current) {
                floodFill(image, r, c, newColor);
            }
        }
        return image;
    }
};
