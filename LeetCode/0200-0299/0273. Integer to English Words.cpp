class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        const unordered_map<int, string> kUnit = {
            {0, ""},
            {1, " Thousand"},
            {2, " Million"},
            {3, " Billion"},
        };
        
        string ret;
        int i = 0;
        for (int i = 0; num > 0; i++, num /= 1000) {
            string s = numberToWordsUnderThousand(num % 1000, kUnit.at(i));
            if (!s.empty()) {
                ret = s + " " + ret;
            }
        }
        
        ret.pop_back();
        return ret;
    }
    
    string numberToWordsUnderThousand(int num, string unit = "") {
        const unordered_map<int, string> kMap = {
            {1, "One"},   {11, "Eleven"},    {10, "Ten"},
            {2, "Two"},   {12, "Twelve"},    {20, "Twenty"},
            {3, "Three"}, {13, "Thirteen"},  {30, "Thirty"},
            {4, "Four"},  {14, "Fourteen"},  {40, "Forty"},
            {5, "Five"},  {15, "Fifteen"},   {50, "Fifty"},
            {6, "Six"},   {16, "Sixteen"},   {60, "Sixty"},
            {7, "Seven"}, {17, "Seventeen"}, {70, "Seventy"},
            {8, "Eight"}, {18, "Eighteen"},  {80, "Eighty"},
            {9, "Nine"},  {19, "Nineteen"},  {90, "Ninety"},
        };
        
        string ret;
        if (num >= 100) {
            ret += " " + kMap.at(num / 100) + " Hundred";
            num %= 100;
        }
        if (num >= 20) {
            ret += " " + kMap.at(num / 10 * 10);
            num %= 10;
        }
        if (num > 0) {
            ret += " " + kMap.at(num);
        }
        
        try {
            return ret.substr(1) + unit;
        } catch (...) {
            return "";
        }
    }
};
