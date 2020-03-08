/*
#include <stdio.h>
#include <string.h>

int Len;
char s[1000000];

int main(){
	int c , i , p;
	while (scanf("%s" , s) , strcmp(s , ".") != 0){
		Len = strlen(s); c = 1; p = -1;
		for(i=1; i<Len; i++){
			p++;
			if(p == c) p = 0;
			if(s[i] != s[p]){
				c = i + 1;
				p = -1;
			}
		}

		if(Len % c == 0) printf("%d\n" , Len / c);
		else printf("1\n");
	}

	return 0;
}
*/

#include <stdio.h>
#include <string.h>

char s[1000001];

int main(){
	int c , i , p;
	while (scanf("%s" , s) , s[0] != '.'){
		c = 1; p = -1;
		for(i=1; s[i] != '\0'; i++){
			p++;
			if(p == c) p = 0;
			if(s[i] != s[p]){
				c = i + 1;
				p = -1;
			}
		}

		if(i % c == 0) printf("%d\n" , i / c);
		else printf("1\n");
	}

	return 0;
}

