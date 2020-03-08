#include <stdio.h>
#include <string.h>

int g0[30][30] , g1[30][30];

int main(){
	int T , t , k , i , j;
	char s[10];
	scanf("%d" , &T);
	for(t=1; t<=T; t++){
		memset(g0 , 0 , sizeof(g0));
		scanf("%d" , &k);
		while(k--){
			scanf("%s" , s);
			if(s[1] == '<') g0[s[0]-'A'][s[2]-'A'] = 1;
			else g0[s[2]-'A'][s[0]-'A'] = 1;
		}
		memcpy(g1 , g0 , sizeof(g0));
		for(k=0; k<26; k++)
			for(i=0; i<26; i++)
				for(j=0; j<26; j++)
					g1[i][j] = g1[i][j] || (g1[i][k] && g1[k][j]);
		printf("Case %d:\n" , t);
		bool printed = 0;
		for(i=0; i<26; i++)
			for(j=0; j<26; j++)
				if(g1[i][j] && !g0[i][j]){
					printed = 1;
					printf("%c<%c\n" , i+'A', j+'A');
				}
		if(!printed) puts("NONE");
	}
	
	return 0;
}
