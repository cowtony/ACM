class Solution {
public:
    string reformatDate(string date) {
        vector<string> dmy = split(date, " ");
        
        string day = dmy[0];
        while (day.back() < '0' or day.back() > '9') {
            day.pop_back();
        }
        if (day.size() == 1) {
            day = "0" + day;
        }
        
        const unordered_map<string, string> month_map{{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, 
                                                      {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, 
                                                      {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, 
                                                      {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        
        return dmy[2] + "-" + month_map.at(dmy[1]) + "-" + day;
    }
    
    vector<string> split(string s, string delimiter) {
        vector<string> res;
        size_t p = 0;
        while (p <= s.length()) {
            size_t pos = s.find(delimiter, p);
            if (pos == string::npos) {
                pos = s.length();
            }
            res.emplace_back(s.substr(p, pos - p));
            p = pos + delimiter.length();
        }
        return res;
    }
};
