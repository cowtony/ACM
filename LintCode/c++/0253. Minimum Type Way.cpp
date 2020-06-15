class Solution {
public:
    /**
     * @param str: the string you wanna print.
     * @return: return the minimum times you need to hit the keyboard.
     */
    int minimumTyping(string &str) {
        vector<int> on(str.length() + 1, 0);
        vector<int> off(str.length() + 1, 0);
        on[0] = 1;
        
        for (int i = 0; i < str.length(); i++) {
            if (str[i] >= 'A' and str[i] <= 'Z') {
                on[i + 1] = min(on[i] + 1, off[i] + 2);
                off[i + 1] = min(on[i] + 2, off[i] + 2);
            } else {
                on[i + 1] = min(on[i] + 2, off[i] + 2);
                off[i + 1] = min(on[i] + 2, off[i] + 1);
            }
        }
        
        return off[str.length()];
    }
};
