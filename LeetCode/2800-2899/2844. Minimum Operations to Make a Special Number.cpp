class Solution {
public:
    int minimumOperations(string num) {
        bool seen_0 = false, seen_5 = false;
        for (int i = num.length() - 1; i >= 0; i--) {
            switch (num[i]) {
            case '0':
                if (seen_0) {  // 00
                    return num.length() - i - 2;
                }
                seen_0 = true;
                break;
            case '2':
                if (seen_5) {  // 25
                    return num.length() - i - 2;
                }
                break;
            case '5':
                if (seen_0) {  // 50
                    return num.length() - i - 2;
                }
                seen_5 = true;
                break;
            case '7':
                if (seen_5) {  // 75
                    return num.length() - i - 2;
                }
            default: 
                continue;
            }
        }

        return num.length() - seen_0;
    }


};
