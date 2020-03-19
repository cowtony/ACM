// LeetCode 305: https://leetcode.com/problems/number-of-islands-ii/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        vector<int> ans;
        for (Point p : operators) {
            addPoint(p.x * m + p.y);
            if (p.x > 0 and father.find((p.x - 1) * m + p.y) != father.end()) {
                connect(p.x * m + p.y, (p.x - 1) * m + p.y);
            }
            if (p.x < n - 1 and father.find((p.x + 1) * m + p.y) != father.end()) {
                connect(p.x * m + p.y, (p.x + 1) * m + p.y);
            }
            if (p.y > 0 and father.find(p.x * m + p.y - 1) != father.end()) {
                connect(p.x * m + p.y, p.x * m + p.y - 1);
            }
            if (p.y < m - 1 and father.find(p.x * m + p.y + 1) != father.end()) {
                connect(p.x * m + p.y, p.x * m + p.y + 1);
            }
            ans.push_back(count);
        }
        return ans;
    }
    
    void addPoint(int p) {
        if (father.find(p) == father.end()) {
            father[p] = p;
            count++;
        }
    }
    void connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra != rb) {
            father[ra] = rb;
            count--;
        }
    }
    int root(int a) {
        if (father[a] == a) {
            return a;
        }
        return father[a] = root(father[a]);
    }
    
private:
    int count = 0;
    unordered_map<int, int> father;
};
