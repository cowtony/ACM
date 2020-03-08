#include <stdio.h>

int n;

int min(int a,int b){
	return a < b ? a : b;
}

int main(){
	int tot;
	int i,j;

	while (scanf("%d",&n) != EOF){
		tot = 0;
		for(i=1; i<=n; i++){
			tot += (1 + i) * i / 2;
			for(j=1; j<=i && j <=n - i; j++){
				tot += i - j + 1;
			}
		}
		printf("%d\n",tot);
	}

	return 0;
}