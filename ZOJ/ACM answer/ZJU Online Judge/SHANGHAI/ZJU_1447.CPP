#include <stdio.h>
#include <string.h>

int m , n;
char s[15][100];
int l1[15] , l2[15] , l3[15];
char str[100];

int jk[15] , c[15][15];

void calc_first(){
	int i , j;
	for(jk[0] = i = 1; i <= 12; i ++) jk[i] = jk[i-1] * i;

	memset(c , 0 , sizeof(c));
	c[1][0] = c[1][1] = 1;
	for(i=2; i<=12; i++){
		c[i][0] = 1;
		for(j=1; j<=i; j++)
			c[i][j] = c[i-1][j] + c[i-1][j-1];
	}	
}

int find_idx(char* str){
	for(int i=0; i<m; i++){
		if(strcmp(s[i] , str) == 0) return i;
	}
}

void solve(){
	int ret = 0;
	int i , j , prev = 0 , t;

	memcpy(l2 , l1 , sizeof(l1));
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			if(l2[j] < l2[i]){
				t = l2[i];
				l2[i] = l2[j];
				l2[j] = t;
			}

	for(i=0; i<n; i++){		
		for(j=prev; j<l2[i]; j++){
			ret += c[m-1-j][n-i-1];
		}
		prev = l2[i] + 1;
	}

	ret *= jk[n];

	
	memcpy(l3 , l1 , sizeof(l1));
	

	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			if(l2[j] == l3[i]){
				l3[i] = j;
				break;
			}
	}
	for(i=0; i<n; i++)
		l1[i] = l3[n-i-1];
	

	for(i=0; i<n; i++){
		t = l1[i];
		for(j=0; j<i; j++)
			if(l1[j] < l1[i]) t--;
		ret += t * jk[n - i - 1];
	}	
	printf("%d\n" , ret + 1);
}

int main(){
//	freopen("in.txt" , "r" , stdin);

	int i;
	calc_first();

	while(scanf("%d %d" , &m , &n) != EOF){
		for(i=0; i<m; i++)
			scanf("%s" , s[i]);
		
		for(i=0; i<n; i++){
			scanf("%s" , str);
			l1[i] = find_idx(str);
		}

		solve();
	}
	
	return 0;
}
