class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int result = 0;
        int y = x;
        while (y)
        {
            result = result * 10 + y % 10;
            y /= 10;
        }
        
        cout << result << endl;
        return result == x;
    }
};
