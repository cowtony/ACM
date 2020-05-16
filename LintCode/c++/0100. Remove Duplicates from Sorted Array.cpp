class Solution {
public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        
        int index = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums.at(i) != nums.at(i - 1))
            {
                nums[index] = nums[i];
                index++;
            }
        }
        
        return index;
    }
};
