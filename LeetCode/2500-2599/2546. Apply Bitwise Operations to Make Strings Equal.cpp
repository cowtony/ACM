// 00->00
// 11->10
// 01->11
// 10->11
// As long as have 1, can switch 0 to 1.

class Solution {
public:
    bool hasOne(string s) {
        return s.find('1') != string::npos;
    }
    
    bool makeStringsEqual(string s, string target) {
        return hasOne(s) == hasOne(target);
    }
};