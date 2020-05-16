class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a string
     */
    string convertToTitle(int n) {
        string result;
        while (n)
        {
            result.insert(result.begin(), (n - 1) % 26 + 'A');
            n = (n - 1) / 26;
        }
        return result;
    }
};
