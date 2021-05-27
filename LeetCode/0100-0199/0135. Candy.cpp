class Solution {
public:
    int candy(vector<int>& ratings) {
        // One pass method. If rating compare previous rating is:
        // Greater: give 1 more candy than previous child.
        // Equal: give same candy as previous child.
        // Less: give 1 candy. What if successive less? We give each previous child in the sequence 1 more.
        int res = 1;
        int previous_candy = 1;
        int previous_top = 0;
        int previous_top_candy = 1;
        
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                ++previous_candy;
                res += previous_candy;
                previous_top = i;
                previous_top_candy = previous_candy;
            } else if (ratings[i] == ratings[i - 1]) {
                previous_candy = 1;
                res += previous_candy;
                previous_top = i;
                previous_top_candy = previous_candy;
            } else { // Equal.
                previous_candy = 1;
                res += i - previous_top;
                if (previous_top_candy == i - previous_top) {
                    res++;
                    previous_top_candy++;
                }
            }
        }
        
        return res;
    }
};
