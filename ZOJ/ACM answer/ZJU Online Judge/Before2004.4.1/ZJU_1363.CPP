#include <stdio.h>
#include <string.h>
int c , n , m;
double f[102];

int main(){
	int i , state;
	while(scanf("%d" , &c) , c){
		scanf("%d %d" , &n , &m);
		if(m > c || m > n || m % 2 != n % 2 ) printf("0.000\n");
		else if(n == 0) printf("1.000\n");
		else{
			memset(f , 0 , sizeof(f));  f[1] = 1;
			for(state = 2; state <= n && state < 500; state++){
				if (state % 2 == 0) f[0] = 1.0 / c * f[1];
				for(i = 2 - (state % 2); i <= c; i+= 2){
					f[i] = double(i + 1) / c * f[i + 1] + double( c - i + 1 ) / c * f[i - 1];
				}
			}
			printf("%.3lf\n" , f[m]);
		}
	}	
	return 0;
}
