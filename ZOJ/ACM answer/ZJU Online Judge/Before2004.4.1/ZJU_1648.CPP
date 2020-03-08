#include <stdio.h>

int n;
struct point{
	double x,y;
};

struct line{
	point p1,p2;
};

line List[2001];

double Multiply(const point& p1,const point& p2,const point& p0){
	return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

bool Cross(const line& L1,const line& L2){
	return (L1.p1.x <= L2.p2.x) && (L2.p1.x <= L1.p2.x) &&
	 	(L1.p1.y <= L2.p2.y) && (L2.p1.y <= L1.p2.y) &&
		(Multiply(L1.p1,L2.p1,L2.p2) * Multiply(L1.p2,L2.p1,L2.p2) <= 0) &&
		(Multiply(L2.p1,L1.p1,L1.p2) * Multiply(L2.p2,L1.p1,L1.p2) <= 0);
}

inline void swap(double & a, double & b){
	double t = a;
	a = b;
	b = t;
}

int main(){
	int i,j;
	bool BURNED;
	while (scanf("%d" , &n) != EOF) {
		for(i = 0;  i < n; i++){
			scanf("%lf %lf %lf %lf",&List[i].p1.x,&List[i].p1.y,&List[i].p2.x,&List[i].p2.y);
			if (List[i].p1.x > List[i].p2.x){
				swap(List[i].p1.x , List[i].p2.x);
			}
			if (List[i].p1.y > List[i].p2.y){
				swap(List[i].p1.y , List[i].p2.y);
			}
		}
		BURNED = false;
		for(i = 0;  i < n; i++){
			for(j=i + 1; j < n; j ++)
				if (Cross(List[i] , List[j])) {
					BURNED = true;
					break;
				}
			if (BURNED) break;
		}

		if (BURNED) printf("burned!\n");else printf("ok!\n");
	}

	return 0;
}

