#include <stdio.h>
#include <string.h>

int n , m , x;

bool f[50][50];

void dp(int p , int k){
	if(f[p][k]) return;
	f[p][k] = 1;
	if(p == m) x = k;
	if(f[m][x]) return;

	int step = k * 2 + 1;
	if(p > step) dp(p - step , k + 1);
	if(p + step <= n) dp(p + step , k + 1);
}

void solve(){
	memset(f , 0 , sizeof(f));
	x = 0;
	dp(1 , 1);
	if(f[m][x]) puts("Let me try!");
	else puts("Don't make fun of me!");
}

int main(){
//	freopen("oopc1d\p3.in" , "r" , stdin);
	while(scanf("%d %d" , &n , &m) , n){
		if(n >= 50) puts("Let me try!");
		else solve();
	}
	
	return 0;
}
