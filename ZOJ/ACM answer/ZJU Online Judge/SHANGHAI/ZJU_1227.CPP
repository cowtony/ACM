#include <stdio.h>
#include <string.h>

int n;
char best;
char list[50][4];
char h[4];
bool f[41][41][41][41];

void dp(char cnt , int stat , char got){
	if(f[ h[0] ][ h[1] ][ h[2] ][ h[3] ]) return;
	f[h[0]][h[1]][h[2]][h[3]] = 1;
	if(cnt >= 5) return;
	if(got > best) best = got;
	char t;
	for(char i=0; i<4; i++)
		if(h[i] < n){
			t = h[i];
			h[i]++;
			if(stat & (1<<list[t][i])) dp(cnt - 1 , stat ^ (1<<list[t][i]) , got + 1);
			else dp(cnt+1 , stat ^ (1<<list[t][i]) , got );
			h[i]--;
		}
}

void solve(){
	memset(h , 0 , sizeof(h));
	memset(f , 0 , 41 * 41 * 41 * 41);
	best = 0;
	dp(0 , 0 , 0);
	printf("%d\n" , best);	
}

int main(){
//	freopen("oopc1d/p1.in" , "r" , stdin);

	int i , j;
	while(scanf("%d" , &n) , n){
		for(i=0; i<n; i++)
			for(j=0; j<4; j++){
				scanf("%d" , &list[i][j]);
				list[i][j]--;
			}
		solve();
	}
	
	return 0;
}
