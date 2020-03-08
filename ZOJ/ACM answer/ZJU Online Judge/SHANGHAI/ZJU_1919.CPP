#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
struct word{
	char s[25];
	bool valid;
	short len;
} list[1010];
short ind[30] , oud[30];
short path[1010] , cnt;
short first[30];

int cmp(const void* a , const void* b){
	return strcmp((char *)a , (char *)b);
}

void init(){
	scanf("%d" , &n);
	memset(ind , 0 , sizeof(ind));
	memset(oud , 0 , sizeof(oud));
	
	short i , st , ed;
	for(i=0; i<n; i++){
		scanf("%s" , list[i].s);
		list[i].valid = 1;
		list[i].len =  strlen(list[i].s) - 1;
	}
	qsort((void *)list , n , sizeof(word) , cmp);
	memset(first , 0xff , sizeof(first));
	for(i=0; i<n; i++){				
		st = list[i].s[0] - 'a'; oud[st]++;
		if(first[st] < 0) first[st] = i;
		ed = list[i].s[ list[i].len ] - 'a'; ind[ed]++;	
	}
}

short find_head(){
	short c1 , c2 , i;
	c1 = c2 = 0;
	for(i=0; i<26; i++){
		if(ind[i] > oud[i] + 1 || oud[i] > ind[i] + 1) return -1;
		if(ind[i] > oud[i]) c1++;
		if(oud[i] > ind[i]) c2++;
	}

	if(c1 >= 2 || c2 >= 2) return -1;
	if(c1 > 0){
		for(i=0; i<26; i++)
			if(oud[i] > ind[i]) return i;
	}
	else{
		for(i=0; i<26; i++)
			if(oud[i]) return i;
	}
}

void euler_path(short u){
	for(short i=first[u-'a']; i<n; i++)
		if(list[i].s[0] == u){
			if(!list[i].valid) continue;
			list[i].valid = 0;			
			euler_path(list[i].s[list[i].len]);
			path[++cnt] = i;
		}
		else break;
}

void solve(){
	short head = find_head();
	if(head < 0){
		puts("***");
	}
	else{
		cnt = 0;
		euler_path(head + 'a');
		if(cnt < n){
			puts("***");
			return;
		}

		for(short i=cnt; i>1; i--) printf("%s." , list[path[i]].s);
		printf("%s\n" , list[path[1]].s);	
		
	}
}

int main(){
//	freopen("C.txt" , "r" , stdin);
//	freopen("ou.txt" , "w" , stdout);

	int T;
	scanf("%d" , &T);
	while(T--){
		init();
		solve();
	}

	return 0;
}
