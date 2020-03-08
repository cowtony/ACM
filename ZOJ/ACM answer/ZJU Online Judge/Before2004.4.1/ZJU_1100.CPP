#include <stdio.h>
#include <string.h>

const int MaxStatus = 1 << 12;
int  n , m;
int Len;
double f0[MaxStatus] , f1[MaxStatus];

void Try(int t , int s , int p , double w){
	if(p > m){
		if (p > m + 1) return;
		f1[t] += w;
	}
	else if( (1 << (p - 1)) & s ){
		Try(t , s , p+1 , w);
	}
	else{		
		Try((1 << (p - 1)) | t , s , p + 1 , w);
		if (! ((1 << p) & s))
			Try(t , s , p + 2 , w);
	}
}

int main(){
	int i , j;
	while (scanf("%d %d" , &n , &m) , m ){
		Len = 1 << m;
		memset(f0 , 0 , sizeof(f0));
		f0[0] = 1;
		for(i = 0; i < n; i++){
			memset(f1 , 0 , sizeof(f1));
			for(j = 0; j < Len; j++)
				if (f0[j] > 0){
					Try(0 , j , 1 , f0[j]);
				}
			memcpy(f0 , f1 , sizeof(f1));
		}
		
		printf("%.0lf\n" ,f0[0]);
	}
	return 0;
}