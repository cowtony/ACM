// disk partial covering problem
// angular sweep O(n*n*logn)
// https://www.geeksforgeeks.org/angular-sweep-maximum-points-can-enclosed-circle-given-radius/
class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
        vector<vector<double>> dist(points.size(), vector<double>(points.size()));
        for (int i = 0; i < points.size(); i++) {
            for (int j = i; j < points.size(); j++) {
                dist[i][j] = dist[j][i] = sqrt((points[i][0] - points[j][0]) 
                                          * (points[i][0] - points[j][0])
                                          + (points[i][1] - points[j][1]) 
                                          * (points[i][1] - points[j][1]));
            }
        }
        
        int max_size = 1;
        for (int i = 0; i < points.size(); i++) {
            max_size = max(max_size, getPointsInside(points, dist, i, 2 * r));
        }
        return max_size;
    }
    
    int getPointsInside(vector<vector<int>>& points, vector<vector<double>>& dist, int idx, double d) {
        // This vector stores alpha and beta and flag 
        // is marked true for alpha and false for beta 
        vector<pair<double, bool>> angles; 

        for (int i = 0; i < points.size(); i++) { 
            if (idx != i and dist[idx][i] <= d) { 
                // acos returns the arc cosine of the complex 
                // used for cosine inverse 
                double B = acos(dist[idx][i] / d); 
                // arg returns the phase angle of the complex 
                double A = atan2(points[i][1] - points[idx][1], points[i][0] - points[idx][0]);
                
                angles.push_back(make_pair(A - B, false)); // Entering
                angles.push_back(make_pair(A + B, true)); // Exiting
            } 
        } 

        // angles vector is sorted and traversed 
        sort(angles.begin(), angles.end());

        // count maintains the number of points inside 
        // the circle at certain value of theta 
        // res maintains the maximum of all count 
        int count = 1, res = 1; 
        for (auto p : angles) { 
            if (p.second == false) { // entry angle 
                count++; 
            } else { // exit angle 
                count--; 
            }
            res = max(res, count);
        } 
        return res; 
    }
};
