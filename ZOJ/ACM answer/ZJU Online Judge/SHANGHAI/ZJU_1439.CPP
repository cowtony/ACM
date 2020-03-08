#include <stdio.h>
#include <math.h>

double a , b , c;
struct point{
	double x , y , z;
} A , B , C;

inline double dist(const point& A , const point& B){
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z));
}

int main(){
	while(scanf("%lf %lf %lf" , &A.x , &A.y , &A.z) != EOF){
		scanf("%lf %lf %lf" , &B.x , &B.y , &B.z);
		scanf("%lf %lf %lf" , &C.x , &C.y , &C.z);

		a = dist(B , C);
		b = dist(A , C);
		c = dist(A , B);
		
		//angle C
		double theta = (a*a+b*b-c*c) / 2.0 / a / b;
		
		theta = sqrt(1 - theta * theta);

		double R = c / theta / 2.0;
		double r = a * b * theta / (a + b + c);

		double t = r / R;


		printf("%.3lf\n" , t * t);
	}

	return 0;
}
