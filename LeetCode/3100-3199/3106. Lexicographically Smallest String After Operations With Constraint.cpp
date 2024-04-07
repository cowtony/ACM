class Solution {
public:
    string getSmallestString(string s, int k) {
        string result;
        
        for (char s1 : s) {
            for (char c = 'a'; c <= 'z'; c++) {
                int dist = minimumDistance(c, s1);
                if (dist <= k) {
                    result += c;
                    k -= dist;
                    break;
                }
            }
        }
        
        return result;
    }
    
    int minimumDistance(char a, char b) {
        if (a > b) {
            return minimumDistance(b, a);
        }
        return min(b - a, a - b + 26);
    }
};
