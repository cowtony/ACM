class Solution {
public:
    /**
     * @param record: Attendance record.
     * @return: If the student should be punished return true, else return false. 
     */
    bool judge(string &record) {
        int count_d = 0;
        int count_l = 0;
        for (char c : record) {
            if (c == 'L') {
                count_l++;
            } else {
                count_l = 0;
                if (c == 'D') {
                    count_d++;
                }
            }
            
            if (count_d >= 2 or count_l >= 3) {
                return true;
            }
        }
        return false;
    }
};
