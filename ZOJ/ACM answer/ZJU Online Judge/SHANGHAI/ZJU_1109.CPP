#include <stdio.h>
#include <string.h>

#define M 233727

struct hash_node
{
	char s0[11] , s1[11];
} list[M];
bool used[M];

inline int ELFhash(char* a){
	unsigned long h = 0;
	while(*a){
		h = (h << 4) + *a++;
		unsigned long g = h & 0Xf0000000L;
		if(g) h^= g >> 24;
		h &= ~g;
	}
	return h % M;
}

void insert(char* s0 , char* s1)
{
	int h = ELFhash(s0);
	while(used[h])
	{
		h = (h + 1) % M;
	}
	used[h] = 1;
	strcpy(list[h].s0 , s0);
	strcpy(list[h].s1 , s1);
}

void init()
{
	char buf[30];
	char s1[11] , s2[11];
	while(1)
	{
		gets(buf);
		if(strlen(buf) == 0) break;
		sscanf(buf , "%s%s" , s1 , s2);

		insert(s2 , s1);
	}
}

void find(char* s0)
{
	int h = ELFhash(s0);
	while(used[h])
	{
		if(strcmp(s0 , list[h].s0) == 0)
		{
			printf("%s\n" , list[h].s1);
			return;
		}
		h = (h + 1) % M;
	}
	puts("eh");
}

void solve()
{
	char buf[11];
	while(scanf("%s" , buf) > 0)
	{
		find(buf);
	}
}

int main()
{
	memset(used , 0 , sizeof(used));
	init();
	solve();
	
	return 0;
}
