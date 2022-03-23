class Solution {
public:
    // This code works for any positive base or negative base.
    string baseNeg2(int n) {
        const int kBase = -2;
        
        if (n == 0) {
            return "0";
        }
        
        string result;
        while (n != 0) {
            int reminder = n % kBase;
            if (reminder < 0) {  // Make reminder a positive value
                reminder += abs(kBase);
                n += kBase;
            }
            n /= kBase;
            
            result += to_string(reminder);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
