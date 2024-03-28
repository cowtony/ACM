class Solution {
    public int rob(int[] nums) {
        int skip = 0;
        int rob = 0;
        for (int num : nums) {
            int temp_skip = skip;
            skip = Math.max(skip, rob);
            rob = temp_skip + num;
        }
        return Math.max(skip, rob);
    }
}
