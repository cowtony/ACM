#include <stdio.h>
#include <string.h>

int n , m;
struct prog{
	char name[15];
	int p;
} list[20];
int s[20];

int im[1025];
int best;

int find_name(char* s){
	for(int i=0; i<n; i++){
		if(strcmp(s , list[i].name) == 0) return i;
	}
	return 1;
}

void init(){
	int i;
	for(i=0; i<n; i++){
		scanf("%s %d" , list[i].name , &list[i].p);
	}

	char buf[200] , next;	

	s[n] = 0;
	for(i=n-1; i>=0; i--){
		s[i] = list[i].p + s[i+1];
	}

	scanf("%d" , &m);	
	
	for(i=0; i<m; i++){
		im[i] = 0;
		while(1){
			scanf("%s" , buf);
			im[i] |= (1<<(find_name(buf)));
			scanf("%c" , &next);
			if(next == '\n') break;
		}		
	}
}

char test_stat(int stat){
	for(int i=0; i<m; i++)
		if((stat & im[i]) == im[i]) return 0;
	return 1;
}

void search(int stat , int p , int got){
	if(got > best){
		best = got;
	}	
	if(s[p] + got <= best){
		return;
	}
	if(test_stat(stat | (1<<p))){
		search(stat | (1<<p) , p + 1 , got + list[p].p);
	}
	search(stat , p + 1 , got);
}

int main(){
//	freopen("in.txt" , "r" , stdin);

	int caseno = 0;
	while(scanf("%d" , &n) , n){
		init();
		best = 0;
		search(0 , 0 , 0);
		printf("System %d: %d\n" , ++caseno , best);		
	}	

	return 0;
}
