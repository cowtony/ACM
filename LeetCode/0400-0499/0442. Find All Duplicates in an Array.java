class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        // Create an array to store the count of each number
        int[] counts = new int[nums.length + 1];

        // Count the occurrences of each number
        for (int num : nums) {
            counts[num]++;
        }

        // Find the numbers that appear twice
        List<Integer> result = new ArrayList<>();
        for (int i = 1; i < counts.length; i++) {
            if (counts[i] == 2) {
                result.add(i);
            }
        }

        return result;
    }
}
