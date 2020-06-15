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
