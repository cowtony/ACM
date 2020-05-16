/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int start = 1, end = n;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (SVNRepo::isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid + 1;
            } 
        }
        return start;
    }
};
