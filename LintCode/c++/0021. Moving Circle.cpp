namespace mniu {
    
typedef struct Vector {
    double x = 0.0, y = 0.0, z = 0.0;
    
    Vector operator - (Vector v) const {
        v.x -= x;
        v.y -= y;
        v.z -= z;
        return v;
    } 
} Point;

double dot(const Vector& a, const Vector& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
Vector cross(const Vector& a, const Vector& b) {
    return {a.y * b.z - b.y * a.z, 
            a.z * b.x - b.z * a.x, 
            a.x * b.y - b.x * a.y};
}
double squaredEuclideanNorm(const Vector& v) {
    return dot(v, v);
}
double euclideanNorm(const Vector& v) {
    return sqrt(squaredEuclideanNorm(v));
}
double squaredEuclideanDistance(const Point& a, const Point& b) {
    return squaredEuclideanNorm(b - a);
}
double euclideanDistance(const Point& a, const Point& b) {
    return sqrt(squaredEuclideanDistance(a, b));
}
};

class Solution {
public:
    /**
     * @param position: the position of circle A,B and point P.
     * @return: if two circle intersect return 1, otherwise -1.
     */
    int IfIntersect(vector<double> &position) {
        mniu::Point A{position[0], position[1]};
        mniu::Point B{position[3], position[4]};
        mniu::Point P{position[6], position[7]};
        double r_a = position[2];
        double r_b = position[5];
        
        if (mniu::euclideanDistance(A, B) < r_a - r_b and mniu::euclideanDistance(P, B) < r_a - r_b) {
            return -1;
        }
        if (mniu::euclideanDistance(A, B) <= r_a + r_b or mniu::euclideanDistance(P, B) <= r_a + r_b) {
            return 1;
        }
        
        mniu::Vector AB = B - A;
        mniu::Vector AP = P - A;
        mniu::Vector PB = B - P;
        mniu::Vector PA = A - P;
        
        if (mniu::dot(AB, AP) < 0 or mniu::dot(PB, PA) < 0) {
            return -1;
        }
        double area = mniu::euclideanNorm(mniu::cross(AP, AB));
        if (area / mniu::euclideanDistance(A, P) <= r_a + r_b) {
            return 1;
        } else {
            return -1;
        }
    }
};
