#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

#define maxn 17343
#define maxp 101

int m;
struct team{
	char name[31] , sort_name[31];
	int solved;
	int p;
	bool uempty;
} list[maxn];

int got[maxn][maxp];

int ELFhash(char* str){
	unsigned long h = 0;
	while(*str){
		h= (h << 4) + *str++;
		unsigned long g = h & 0Xf0000000L;
		if(g) h^= g >> 24;
		h &= ~g;
	}
	return h % maxn;
}

int find_name(char* name , char* sort_name){
	int h = ELFhash(sort_name);
	while(list[h].uempty == 1){
		if(strcmp(sort_name , list[h].sort_name) == 0) return h;
		h = (h + 1) % maxn;
	}

	strcpy(list[h].name , name);
	strcpy(list[h].sort_name , sort_name);

	list[h].solved = list[h].p = 0;
	list[h].uempty = 1;

	return h;
}

bool cmp(const team& a, const team& b){
	if(a.solved != b.solved) return a.solved > b.solved;
	if(a.p != b.p) return a.p < b.p;
	return strcmp(a.sort_name , b.sort_name) < 0;
}

void print_team(int rank , int i){
	if(rank){
		printf("%-10d" , rank);
	}
	else printf("          ");

	printf("%-30s" , list[i].name);
	printf("%-10d" , list[i].solved);
	printf("%d\n" , list[i].p);
}

int main(){
	scanf("%d" , &m);

	int submit_time , problem , idx;
	char s[31] , judge[5];
	char sort_s[31];
	int i;

	memset(got , 0 , sizeof(got));
	memset(list, 0 , sizeof(list));
	while(scanf("%d" ,&submit_time)!=EOF){
		scanf("%s" , s);
		scanf("%d" , &problem);
		scanf("%s" , judge);

		strcpy(sort_s , s);
		for(i=strlen(s) - 1; i>=0; i--){
			sort_s[i] = tolower(sort_s[i]);
		}

		idx = find_name(s , sort_s);
		if(got[idx][problem] == -1) continue;
		if(judge[0] == 'A'){
			list[idx].solved ++;
			list[idx].p += submit_time + got[idx][problem];
			got[idx][problem] = -1;
		}
		else{
			got[idx][problem] += 20;
		}
	}

	sort(list , list + maxn , cmp);
	int rank = 1;
	if(list[0].solved == 0) return 0;
	print_team(1 , 0);

	for(i=1; i<maxn; i++){
		if(list[i].solved == 0) break;
		if(list[i].solved == list[i-1].solved && list[i].p == list[i-1].p){
			print_team(0 , i);
			rank++;
		}
		else{
			print_team(++rank , i);
		}
	}

	return 0;
}
