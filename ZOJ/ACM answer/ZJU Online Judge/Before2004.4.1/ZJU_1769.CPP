#include <stdio.h>
#include <math.h>

const double pi = 2 * acos(0);

double dist(double x1 , double y1 , double x2 , double y2){
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int Equal(double d1 , double d2){
	return fabs(d1 - d2) <= 0.01;
}

void swap(double& a , double& b){
	double t = a;
	a = b; b = t;
}

int main(){	
	//freopen("q1769.in" , "r" , stdin);
	//freopen("out.txt" , "w" , stdout);

	double x1 , x2 , x3 , y1 , y2 , y3;
	double d1 , d2 , d3;
	double deg;

	while(scanf("%lf" , &x1) , scanf("%lf%lf%lf%lf%lf",&y1,&x2,&y2,&x3,&y3) != EOF){		
		d1 = dist(x1 , y1 , x2 , y2);
		d2 = dist(x2 , y2 , x3 , y3);
		d3 = dist(x3 , y3 , x1 , y1);
		if(d1 < d2) swap(d1 , d2);
		if(d1 < d3) swap(d1 , d3);
		if(d2 < d3) swap(d2 , d3);

		if(Equal(d1 , d2 + d3)){
			printf("Not a Triangle\n"); continue;
		}

		int ret = Equal(d1 , d2) + Equal(d2 , d3);
		
		if(ret == 0){
			printf("Scalene ");
		}
		else if(ret == 1){
			printf("Isosceles ");
		}
		else printf("Equilateral ");

		deg = acos((d2 * d2 + d3 * d3 - d1 * d1) / 2 / d2 / d3) * 180 / pi;		

		if(deg > 92){
			printf("Obtuse\n");
		}
		else if(deg >= 88){
			printf("Right\n");
		}
		else printf("Acute\n");
		
	}	
	printf("End of Output\n");	
	return 0;
}
