#include <stdio.h>
#include <math.h>
#define MAXN 1010
int n;
struct point{
	double x,y;
};
point List[MAXN];

inline double max(const double& a, const double& b){
	return a > b ? a : b;
}

inline double min(const double& a, const double& b){
	return a < b ? a : b;
}

double Multiple(const point& p1,const point& p2,const point& p0){
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool Cross(const point u1,const point& u2,const point& v1,const point& v2){
	return ((max(u1.x,u2.x) >= min(v1.x,v2.x)) &&
		(max(v1.x,v2.x) >= min(u1.x,u2.x)) &&
		(max(u1.y,u2.y) >= min(v1.y,v2.y)) &&
		(max(v1.y,v2.y) >= min(u1.y,u2.y)) &&
		(Multiple(v1,u2,u1) * Multiple(v2,u2,u1) <= 0) &&
		(Multiple(u1,v2,v1) * Multiple(u2,v2,v1) <= 0));	
}

bool CalcArea(){
	if (n < 3) return 0;
	int i,j;

	for(i=0; i<n; i++)
		for(j=i+2; j<n; j++){
			if (i == 0 && j == n-1) continue;
			if (Cross( List[i], List[i+1], List[j], List[j+1] )) return 0;
		}

	double Area = 0;
	for(i=0; i<n; i++){
		Area = Area + List[i].x * List[i+1].y - List[i].y * List[i + 1].x;
	}
	
	Area = fabs(Area / 2.0);	
	printf("%.2lf\n" , Area);
	return 1;	
}


int main(){
	int i;	
	int CaseNo = 0;
	while(scanf("%d" , &n) , n){
		for(i=0; i<n; i++)
			scanf("%lf %lf" , &List[i].x , &List[i].y);
		List[n] = List[0];

		if (CaseNo > 0) printf("\n");
		printf("Figure %d: ", ++CaseNo);
		if (! CalcArea()){
			printf("Impossible\n");
		}
	}

	return 0;
}