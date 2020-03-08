#include <stdio.h>
#include <string.h>

#define M 105143

char s[20] , s1[20] , s2[20];
char word[25200][20];
short int len[25200];
short int Q[25200] , dist[25200] , prev[25200];
int n;
int table[M];
int head , tail;
int id1 , id2;

int ELFhash(char*s)
{
	unsigned long h = 0;
	while(*s)
	{
		h = (h<<4)+*s++;
		unsigned long g = h & 0Xf000000L;
		if(g) h^= g >> 24;
		h &= ~g;
	}
	return h % M;
}

void add_hash()
{
	int h = ELFhash(s);
	while(table[h])
	{
		h = (h + 1) % M;
	}
	table[h] = n;
}

void specail_add(char*s , int sn , int& h , int& id)
{
	id = sn;
	strcpy(word[sn] , s);

	h = ELFhash(s);
	int h1 = h;
	while(table[h])
	{
		h = (h + 1) % M;
	}
	table[h] = sn;
}

void read_words()
{
	n = 0;
	while(1)
	{
		gets(s);
		if(strcmp(s , "") == 0) break;
		strcpy(word[++n] , s);
		len[n] = strlen(s);
		add_hash();
	}
}

int find_word(char*s)
{
	int h = ELFhash(s);
	while(table[h])
	{
		if(strcmp(word[table[h]] , s) == 0) return table[h];
		h = (h + 1) % M;
	}
	return 0;
}

void print_route(int u)
{
	if(u)
	{
		print_route(prev[u]);
		printf("%s\n" , word[u]);
	}
}

bool push(short id , short d , short ancestor)
{	
	if(dist[id] < 0)
	{
		Q[++tail] = id;
		dist[id] = d;
		prev[id] = ancestor;
	}
	if(id == id2)
	{
		print_route(id);
		return 1;
	}
	return 0;
}

bool extend(int id , int d)
{
	int i , new_id;
	char prev;
	strcpy(s , word[id]);
	for(i=0; i<len[id]; i++)
	{
		prev = s[i];
		for(s[i]='a'; s[i]<prev; s[i]++)
		{
			new_id = find_word(s);
			if(new_id)
			{
				if(push(new_id , d , id)) return 1;
			}
		}
	}
	for(i=len[id]-1; i>=0; i--)
	{
		prev = s[i];
		for(s[i]++; s[i] <= 'z'; s[i]++)
		{
			new_id = find_word(s);
			if(new_id)
			{
				if(push(new_id , d , id)) return 1;
			}
		}
		s[i] = prev;
	}

	return 0;
}

void solve()
{
	if(strlen(s1) != strlen(s2))
	{
		puts("No solution.");
		return;
	}
	int h1 , h2;
	h1 = h2 = -1;

	id1 = find_word(s1);	
	if(id1 == 0)
	{
		specail_add(s1 , n+1 , h1 , id1);
	}
	id2 = find_word(s2);
	if(id2 == 0)
	{
		specail_add(s2 , n+2 , h2 , id2);
	}

	head = 0; tail = -1;
	memset(dist , 0xff , sizeof(dist));
	push(id1 , 0 , 0);

	while(head <= tail)
	{
		if(extend(Q[head] , dist[Q[head]]+1)) return;
		head++;
	}

	if(h1 >= 0)
	{
		table[h1] = 0;
	}

	if(h2 >= 0)
	{
		table[h2] = 0;
	}

	puts("No solution.");
}

int main()
{
	freopen("in.txt" , "r" , stdin);
	
	read_words();
	
	bool first = 1;
	while(scanf("%s%s" , s1 , s2) > 0)
	{
		if(first) first = 0 ; else putchar('\n');
		solve();
	}
	
	return 0;
}
