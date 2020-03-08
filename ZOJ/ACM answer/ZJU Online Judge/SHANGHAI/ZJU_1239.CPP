#include <stdio.h>
#include <string.h>
#include <math.h>

int n , p;
int top[51];

inline bool is_sqr(int k){
	return  int(sqrt(double(k))) * int(sqrt(double(k))) == k;
}

bool putin(int k){
	for(int i=0; i<p; i++)
		if(is_sqr(top[i] + k)){
			top[i] = k;
			return 1;
		}
	if(p == n) return 0;
	top[p++] = k;
	return 1;
}

void solve(){
	memset(top , 0 , sizeof(top));
	p = 0;

	int UpLimit;
	for(UpLimit = 1; ; UpLimit++){
		if(! putin(UpLimit)) break;
	}

	printf("%d\n" , UpLimit - 1);
}

int main(){
//	freopen("in-ans/p7.in" , "r" , stdin);

	int T;
	scanf("%d" , &T);

	while(T--){
		scanf("%d" , &n);
		solve();
	}
	
	return 0;
}
