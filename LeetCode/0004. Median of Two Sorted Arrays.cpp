class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *shortNums, *longNums;
        if (nums1.size() < nums2.size()) {
            shortNums = &nums1;
            longNums = &nums2;
        }
        else {
            shortNums = &nums2;
            longNums = &nums1;
        }
        
        const int totalLen = nums1.size() + nums2.size();
        int left = 0, right = shortNums->size();
        int shortCut, longCut;
        while (left <= right) {
            shortCut = (left + right) / 2;
            longCut = totalLen / 2 - shortCut;
            cout << shortCut << ' ' << longCut << endl;
            try {
                if (shortNums->at(shortCut - 1) > longNums->at(longCut)) {
                    right = shortCut - 1; // need to move shortCut left
                    continue;
                }
            } catch (...) {}
                
            try {
                if (longNums->at(longCut - 1) > shortNums->at(shortCut)) {
                    left = shortCut + 1; // need to move shortCut right
                    continue;
                }
            } catch (...) {}
                
                  
            break;
        }
        cout << "Binary Search end" << endl;
        
        if (totalLen % 2 == 0)
        {
            int left = -2100000000;
            try {
                left = max(left, shortNums->at(shortCut - 1));
            } catch(...){}
            try {
                left = max(left, longNums->at(longCut - 1));
            } catch(...){}
            
            int right = 2100000000;
            try {
                right = min(right, shortNums->at(shortCut));
            } catch(...){}
            try {
                right = min(right, longNums->at(longCut));
            } catch(...){}
            cout << "Even:" << left << ' ' << right << endl;
            return (left + right) / 2.0;
        }
            
        else {
            int ret = 2100000000;
            try {
                ret = min(ret, shortNums->at(shortCut));
            } catch(...){}
            try {
                ret = min(ret, longNums->at(longCut));
            } catch(...){}
            return ret;
        }
            
    }
};
