#include <stdio.h>
#include <string.h>

#define MAXLEN 100000
char s1[MAXLEN] , s2[MAXLEN];

int main(){
	int l1 , l2 , i , p;
	while(scanf("%s %s" , s1 , s2) != EOF){
		l1 = strlen(s1);
		l2 = strlen(s2);
		p = 0;
		for(i=0; i<l1 && p < l2; i++ , p++){
			while(p < l2 && s2[p] != s1[i]) ++p;			
		}
		if(p <= l2) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
