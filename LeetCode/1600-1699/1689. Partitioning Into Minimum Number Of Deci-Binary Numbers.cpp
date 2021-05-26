class Solution {
public:
    int minPartitions(string n) {
        char max_digit = 0;
        for (char c : n) {
            max_digit = max(max_digit, c);
        }
        return max_digit - '0';
    }
};
