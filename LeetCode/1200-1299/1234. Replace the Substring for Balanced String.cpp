class Solution {
public:
    int balancedString(string s) {
        const int kMax = s.length() / 4;
        int left = 0, right = s.length() - 1;
        vector<int> count(26, 0);

        while (right >= 0 && count[s[right] - 'A'] < kMax) {
            count[s[right] - 'A']++;
            right--;
        }
        right++;

        int result = right;
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'A']++;
            while (right < s.length() && count[s[i] - 'A'] > kMax) {
                count[s[right] - 'A']--;
                right++;
            }
            if (count[s[i] - 'A'] > kMax) {
                break;
            }

            result = min(result, right - i - 1);
        }
        return result;
    }
};
