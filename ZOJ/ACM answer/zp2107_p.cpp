#include <cstdio> 
#include <cmath> 
#include <cstdlib> 

using namespace std; 

const int Maxn = 100010; 
const double inf = 1e19; 

struct Point { 
    double x, y; 
}; 

Point P[Maxn]; 
int   N; 

double Dis(Point a, Point b) { 
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); 
} 

int Cmp(void const *a, void const *b) { 

    Point p1 = *(Point*)a, p2 = *(Point*)b; 
    if (p1.x+p1.y < p2.x+p2.y) { 
        return -1; 
    } 
    return 1; 
} 

int Init() { 

    scanf("%d", &N); 
    for (int k=0; k<N; k++) { 
        scanf("%lf%lf", &P[k].x, &P[k].y); 
    } 
    qsort(P, N, sizeof(P[0]), Cmp); 
    
    return N; 
} 

double Solve() { 
    double Min = inf, t; 
    int i, j; 
    
    for (i=0; i<N; i++) { 
        for (j=i+1; j<i+20 && j<N; j++) { 
            t = Dis(P[i], P[j]); 
            if (t < Min) { 
                Min = t; 
            } 
        } 
    } 
    
    return sqrt(Min)/2; 
} 

int main() { 

    while (Init() != 0) { 
        printf("%.2lf\n", Solve()); 
    } 
    
    return 0; 
}