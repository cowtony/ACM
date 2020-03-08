#include <stdio.h>
#include <string.h>

const int Len = 1 << 15;
bool prim[32768];

int main(){
	int n;
	int count;
	int i , k ;
	memset(prim , 1 , sizeof(prim));
	for(i=2; i<Len; i++)
		if(prim[i]){
			k = i + i;
			while(k < Len){
				prim[k] = 0;
				k += i;
			}
		}

	while(scanf("%d" , &n) , n ){
		count = 0;
		for(i=2; i<=n/2; i++){
			if(prim[i] && prim[n - i]) count++;
		}
		printf("%d\n" , count);
	}
	
	return 0;
}
