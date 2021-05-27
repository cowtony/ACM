class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<int> visited;
        int x = 0, y = 0;
        visited.insert({x, y});
        for (char c : path) {
            switch (c) {
                case 'N': x--; break;
                case 'S': x++; break;
                case 'E': y++; break;
                case 'W': y--; break;
            }
            
            if (visited.find(x * 10000 + y) != visited.end()) {
                return true;
            }
            visited.insert(x * 10000 + y);
        }
        return false;
    }
};
