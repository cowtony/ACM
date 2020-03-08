#include <stdio.h>
#include <string.h>

#define LEN 1000000

int L;
char s[LEN];
int pi[LEN];

int main(){
	int q , k , i;
	int max;
	while(scanf("%s" , s) , strcmp(s , ".") != 0){
		L = strlen(s);
		k = -1;
		pi[0] = -1;
		for(q=1; q<L; q++){
			while(k>=0 && s[k + 1] != s[q])
				k = pi[k];
			if(s[k + 1] == s[q]) k++;
			pi[q] = k;
		}
		max = 1;
		for(i=0; i<L; i++)
			if(i - pi[i] > max) max = i - pi[i];
		if(L % max == 0){
			printf("%d\n" , L / max);
		}
		else printf("1\n");
	}
	
	return 0;
}
