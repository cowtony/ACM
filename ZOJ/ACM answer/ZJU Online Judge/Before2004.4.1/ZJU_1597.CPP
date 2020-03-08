#include <stdio.h>
#include <math.h>
const double pi = 2 * acos(0);

double X1 , Y1 , R1 , X2 , Y2 , R2;
double len , Area;

double min(double a , double b){
	return a < b ? a : b;
}

int main(){
	while(scanf("%lf %lf %lf %lf %lf %lf" ,&X1 , &Y1 , &R1 , &X2 , &Y2 , &R2) != EOF){
		len = sqrt( (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2) );
		if (len >= R1 + R2) Area = 0;
		else if(len <= fabs(R1 - R2)) Area = pi * min(R1 , R2) * min(R1 , R2);
		else{
			double theta1 = acos( (R1*R1+len*len-R2*R2) / 2 / R1 / len ) * 2;
			double theta2 = acos( (R2*R2+len*len-R1*R1) / 2 / R2 / len ) * 2;
			Area = R1 * R1 * (theta1 - sin(theta1)) / 2
				 + R2 * R2 * (theta2 - sin(theta2)) / 2;	
		}
		printf("%.3lf\n" , Area);
	}

	return 0;
}