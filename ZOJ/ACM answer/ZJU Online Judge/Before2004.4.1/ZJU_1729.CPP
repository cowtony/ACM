#include <stdio.h>
#include <string>

int Len;
char buf[210000];

void solve(){
	int p0 , p1 , k;
	p0 = 0; p1 = 1;

	while(p0 < Len && p1 < Len){
		for(k = 0; k < Len; k++)
			if(buf[p0 + k] != buf[p1 + k]) break;

		if(k == Len){
			break;
		}
		else{
			if(buf[p0 + k] > buf[p1 + k]) p0 = p0 + k + 1;
			else p1 = p1 + k + 1;
			if(p0 == p1) p1++;
		}
	}

	printf("%d\n" , p0 < p1 ? p0 : p1);
}

int main(){
	freopen("b.in" , "r" , stdin);
	int T;
	scanf("%d" , &T);
	while(T--){
		scanf("%d %s" , &Len , buf);
		for(int i=0; i<Len; i++)
			buf[i + Len] = buf[i];

		solve();
	}
	
	return 0;
}
