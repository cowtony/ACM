#include <stdio.h>
#include <string.h>

#define maxn 5010
int n , m;

struct node{
	short v;
	node *next;
};

node *list[maxn] , *elist[maxn];
short mark[maxn] , p[maxn];
bool valid[maxn];

void init()
{
	for(int i=0; i<n; i++)
	{
		list[i] = new node;
		list[i]->next = NULL;

		elist[i] = new node;
		elist[i]->next = NULL;
	}

	scanf("%d" , &m);
	int a , b;
	node *t;

	while(m--)
	{
		scanf("%d %d" , &b , &a);
		a-- , b--;

		t = new node;
		t->v = b;
		t->next = list[a]->next;
		list[a]->next = t;

		t = new node;
		t->v = a;
		t->next = elist[b]->next;
		elist[b]->next = t;
	}
}

int time;

void dfs_1(int u)
{
	mark[u] = 1;
	node *t = list[u];
	while(t->next != NULL)
	{
		t = t->next;
		if(!mark[t->v]) dfs_1(t->v);
	}

	p[time++] = u;
}

void dfs_2(int u)
{
	mark[u] = time;
	node *t = elist[u];
	while(t->next != NULL)
	{
		t = t->next;
		if(!mark[t->v]) dfs_2(t->v);
	}
}

void solve()
{
	int i;
	time = 0;
	memset(mark , 0 , sizeof(mark));
	for(i=0; i<n; i++)
		if(!mark[i]) dfs_1(i);
	
	time = 0;
	memset(mark , 0 , sizeof(mark));
	for(i=n-1; i>=0; i--)
		if(!mark[p[i]])
		{
			++time;
			dfs_2(p[i]);	
		}


	///////produce answer
	memset(valid , 1 , sizeof(valid));
	for(i=0; i<n; i++)
		if(valid[mark[i]])
		{
			node* t = elist[i];
			while(t->next != NULL)
			{
				t = t->next;
				if(mark[t->v] != mark[i])
				{
					valid[mark[i]] = 0;
					break;
				}
			}
		}
	
	bool first = 1;
	for(i=0; i<n; i++)
		if(valid[mark[i]])
		{
			if(first) first = 0;
			else putchar(' ');
			printf("%d" , i + 1);
		}
	putchar('\n');
}

int main(){
//	freopen("bottom.in" , "r" , stdin);
//	freopen("out.txt" , "w" , stdout);
	
	while(scanf("%d" , &n) , n)
	{
		init();
		solve();
	}
	
	return 0;
}
