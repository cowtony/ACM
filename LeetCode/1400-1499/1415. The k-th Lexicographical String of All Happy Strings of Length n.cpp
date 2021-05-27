class Solution {
public:
    string getHappyString(int n, int k) {
        k--; // Change to 0 starting index.
        
        const map<char, char> small = {{'a', 'b'}, {'b', 'a'}, {'c', 'a'}};
        const map<char, char> large = {{'a', 'c'}, {'b', 'c'}, {'c', 'b'}};
        
        int total = 3 * (1 << (n - 1));
        if (k >= total) {
            return "";
        }
        total /= 3;
        
        string s;
        s += char('a' + k / total);  // Add the first letter
        k %= total;
       
        for (int i = 1; i < n; i++) {
            total >> = 1;

            if (k >= total) {
                s += large.at(s[i - 1]);
                k %= total;
            } else {
                s += small.at(s[i - 1]);
            }
        }
        
        return s;
    }
};
