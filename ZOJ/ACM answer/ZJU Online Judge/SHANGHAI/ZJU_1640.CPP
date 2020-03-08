#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int p[30] , q[30];
int ans[30];
int cnt;

int cmp(const void* a , const void* b){
	return (*(int*)a) - (*(int*)b);
}

char check(int c){
	int ret = p[0];
	int w = 1;
	for(int i=1; i<=n; i++){
		w *= c;
		ret += w * p[i];
	}

	return (ret == 0);
}

void divi(int c){
	// div (x - c)
	memset(q , 0 , sizeof(q));
	for(int i = n-1; i >= 0; i --){
		q[i] = p[i+1];
		p[i] += c * q[i];
	}
	memcpy(p , q , sizeof(p));	
}

void solve(){

	int c , p0;
	int found;

	cnt = 0;
	for(; n; n--){
		if(p[0] == 0){
			ans[cnt++] = 0;
			for(int i=0; i<n; i++)
				p[i] = p[i+1];
			continue;
		}	

		found = 0;		

		for(c = 1; c * c <= abs(p[0]); c++){
			if(p[0] % c > 0) continue;
			if(check(c)){
				ans[cnt++] = c;
				divi(c);
				found = 1;
				break;
			}
			if(check(-c)){
				ans[cnt++] = -c;
				divi(-c);
				found = 1;
				break;
			}
			if(check(p[0] / c)){
				ans[cnt++] = p[0] / c;
				divi(p[0] / c);
				found = 1;
				break;
			}
			if(check(-p[0] / c)){
				ans[cnt++] = -p[0] / c;
				divi(-p[0] / c);
				found = 1;
				break;
			}
		}

		if(!found) break;
	}

	if(cnt == 0){
		puts("NIR");
		return;
	}
	
	qsort((void *)ans , cnt , sizeof(int) , cmp);
	printf("%d" , ans[0]);
	for(int i=1; i<cnt; i++)
		printf(" %d" , ans[i]);
	putchar('\n');
}

int main(){

//	freopen("in.txt" , "r" , stdin);

	int T;
	scanf("%d" , &T);
	
	while(T--){
		scanf("%d" , &n);
		for(int i=n; i>=0; i--)
			scanf("%d" , p + i);

		solve();		
	}

	return 0;
}
