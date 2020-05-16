class Solution {
public:
    /**
     * @param interval_A: a string represent a interval.
     * @param interval_B: a string represent a interval.
     * @return: if two intervals can merge return true, otherwise false.
     */
    bool MergeJudge(string &interval_A, string &interval_B) {
        string a1 = interval_A.substr(1, interval_A.find(',') - 1);
        string a2 = interval_A.substr(interval_A.find(',') + 1);
        a2.pop_back();
        
        string b1 = interval_B.substr(1, interval_B.find(',') - 1);
        string b2 = interval_B.substr(interval_B.find(',') + 1);
        b2.pop_back();
        
        if (interval_B.front() == '[') {
            a2 += 'a';
        }
        if (interval_A.front() == '[') {
            b2 += 'a';
        }
        if (interval_B.back() == ']') {
            b2 += 'a';
        }
        if (interval_A.back() == ']') {
            a2 += 'a';
        }
        
        return a2 > b1 and b2 > a1;
    }
};
