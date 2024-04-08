class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count(2, 0);
        for (int student : students) {
            count[student]++;
        }
        for (int sandwiche : sandwiches) {
            if (count[sandwiche] > 0) {
                count[sandwiche]--;
            } else {
                break;
            }
        }
        return count[0] + count[1];
    }
};
