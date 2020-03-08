#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n;
char g[30][30];
int ind[30] , oud[30];

char s[1010];
char mark[30];

void dfs(int u){
	mark[u] = 1;
	for(int v = 0; v < 26; v++)
		if(g[u][v] && !mark[v]) dfs(v);
}

char solve(){
	int i;
	char flag = 0;
	memset(mark , 0 , sizeof(mark));
	for(i=0; i<26; i++)
		if(oud[i] == ind[i] + 1){
			dfs(i); flag = 1;
			break;
	}
	if (!flag)
		for(i=0; i<26; i++)
			if(oud[i]){
				dfs(i);
				break;
			}
	for(i=0; i<26; i++)
		if(ind[i] || oud[i])
			if(!mark[i]) return 0;
	int cnt1 = 0 , cnt2 = 0;
	for(i=0; i<26; i++){
		if(abs(ind[i] - oud[i]) >= 2) return 0;
		if(ind[i] == oud[i] + 1) ++ cnt1;
		if(ind[i] == oud[i] - 1) ++ cnt2;
		if(cnt1 > 1 || cnt2 > 1) return 0;
	}

	puts("Ordering is possible.");
	return 1;
}

int main(){
	freopen("in.txt" , "r" , stdin);
	int T , len;
	scanf("%d" , &T);
	while(T--){
		scanf("%d" , &n);
		memset(g , 0 , sizeof(g));
		memset(ind , 0 , sizeof(ind));
		memset(oud , 0 , sizeof(oud));
		while(n--){
			scanf("%s" , s);
			len = strlen(s) - 1;
			oud[s[0]-'a']++;
			ind[s[len]-'a']++;
			g[s[0]-'a'][s[len]-'a'] = 1;
		}

		if(!solve()) puts("The door cannot be opened.");
	}

	return 0;
}
