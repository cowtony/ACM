class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int tests = minutesToTest / minutesToDie + 1; // One more tests for not drink anything.
        
        // pigs ^ tests >= buckets
        return ceil(log(buckets) / log(tests));
    }
};
