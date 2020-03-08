#include <stdio.h>
#include <string.h>

int t;
char s0[100] , s1[100];
int l1 , l2;

void solve(){
	l1 = strlen(s0);
	l2 = strlen(s1);

	int i;
	for(i=0; i<l1 && i<l2; i++)
		if(s0[i] != s1[i]){
			printf("%d\n" , (l1 + l2 - i - i) * t); return;
		}
	printf("%d\n" , (l1 + l2 - i - i) * t);
}

int main(){
	int n;
	scanf("%d" , &n);
	char buf[10];
	while(n--){
		scanf("%d" , &t);
		gets(buf);
		gets(s0);
		gets(s1);

		solve();
	}
	
	return 0;
}
