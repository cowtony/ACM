class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back('*');
        int ptr = 0;
        int counter = 1;
        for (int i = 1; i < chars.size(); ++i) {
            if (chars[i] == chars[i - 1]) {
                counter++;
            } else {
                chars[ptr++] = chars[i - 1];
                if (counter > 1) {
                    for (char c : to_string(counter)) {
                        chars[ptr++] = c;
                    }
                }
                counter = 1;
            }
        }
        return ptr;
    }
};
