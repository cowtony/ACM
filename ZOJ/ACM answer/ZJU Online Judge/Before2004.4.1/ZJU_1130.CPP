#include <stdio.h>
#include <string.h>

bool mark[1 << 15];
int n,k;

int main(){
	int Len , p , Count ;	
	while(scanf("%d %d" , &n ,&k) , n){
		p = Len = (1 << n) - 1;
		k = (k + n) & Len;
		Count = 0;
		memset(mark , 0 , sizeof(mark));
		for(int i=0; i<k; i++){
			if(!mark[(p << 1) & Len]){
				// put 0
				p = (p << 1) & Len;
				mark[p] = 1;
			}
			else{
				// put 1
				p = ((p << 1) | 1) & Len;
				mark[p] = 1;
			}
		}
		printf("%d\n" , p);
	}
	
	return 0;
}