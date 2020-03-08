#include <stdio.h>
#include <string.h>

#define LEN 500
char x[LEN] , y[LEN];
int Lenx , Leny;
int f[2][LEN];

void solve(){
	int prev , cur = 0;
	int i;
	memset(f , 0 , sizeof(f));
	for(i=0; i<Leny; i++){
		f[cur][i] = (x[0] == y[i]);
		if(i > 0 && !f[cur][i]) f[cur][i] = f[cur][i-1];
	}
	for(int t=1; t<Lenx; t++){
		prev = cur; cur = 1 - cur;

		f[cur][0] = (x[t] == y[0]);
		if(! f[cur][0]) f[cur][0] = f[prev][0];
		for(i=1; i<Leny; i++){
			if(x[t] == y[i]) f[cur][i] = f[prev][i-1] + 1;
			else f[cur][i] = 0;
			if(f[cur][i-1] > f[cur][i]) f[cur][i] = f[cur][i-1];
			if(f[prev][i] > f[cur][i]) f[cur][i] = f[prev][i];
		}
	}

	printf("%d\n" , f[cur][Leny-1]);

}

int main(){
	//freopen("f.in" , "r" , stdin);

	while(scanf("%s %s" , x , y) != EOF){
		Lenx = strlen(x); Leny = strlen(y);
		solve();
	}
	
	return 0;
}
