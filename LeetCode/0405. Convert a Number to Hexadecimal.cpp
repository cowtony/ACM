class Solution {
public:
    string toHex(int num) {
        stringstream stream;
        cout << hex << num;
        return stream.str();
    }
};
