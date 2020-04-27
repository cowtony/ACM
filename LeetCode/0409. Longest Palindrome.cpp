class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> dict;
        for (char c : s)
        {
            dict[c]++;
        }

        int hasOdd = 0;
        int length = 0;
        for (pair<char, int> p : dict)
        {
            length += (p.second / 2) * 2;

            if (p.second % 2 == 1)
                hasOdd = 1;
        }
        return length + hasOdd;
    }
};
