class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // get num_1 ^ num_2:
        int diff = 0;
        for (int num : nums) {
            diff ^= num;
        }
        
        diff &= -diff;   // get LSB bit 1
        
        vector <int> result = {0, 0};
        for (int num : nums) {
            if ((num & diff) == 0) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }
        return result;
    }
};
