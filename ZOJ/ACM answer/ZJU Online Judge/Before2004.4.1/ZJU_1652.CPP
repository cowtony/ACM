#include <stdio.h>
int n;
double ans;
int main(){
	int i;
	double w;
	while(scanf("%d" , &n) != EOF){
		if(n == 0){ printf("1\n"); continue; }
		ans = 1;
		w = 0;
		for(i=1; i<=n; i++){
			w++;
			ans += w*2;
			w+=2;
			ans += w;
		}
		ans -= 4*n;
		printf("%.0lf\n",ans);
	}
	
	return 0;
}
