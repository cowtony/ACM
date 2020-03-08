#include <stdio.h>
#include <math.h>

double R , r;

int main(){
	double ret;
	while(scanf("%lf %lf" , &R , &r) != EOF){
		if(r > R){
			printf("Coin cannot fit in tray.\n"); continue;
		}		
		if (r > R / 2.0){
			printf("1 coin of size %.0lf will fit the inner rim of a tray of size %.0lf.\n" , r , R);
			continue;
		}			

		ret =floor(acos(0) * 2 / asin(double(r) / (R - r)) + 1e-9);
		
		printf("%.0lf coins of size %.0lf will fit the inner rim of a tray of size %.0lf.\n" , ret , r , R);
	}
	
	return 0;
}
