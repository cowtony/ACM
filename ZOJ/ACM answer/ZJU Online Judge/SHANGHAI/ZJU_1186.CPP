#include <stdio.h>
#include <string.h>

int n , m;

#define maxn 1010

struct node{
	short int v;
	bool dir;
	node *next;
};

node *list[maxn];

short int enter[maxn] , low[maxn] , father[maxn];

void add_edge(int a ,int b)
{
	node *t = new node;
	t->next = list[a]->next;
	t->v = b;
	t->dir = 0;
	list[a]->next = t;		
}

void init()
{
	int a , b;
	
	for(int i=0; i<n; i++)
	{
		list[i] = new node;
		list[i]->next = NULL;
	}

	while(m--)
	{
		scanf("%d%d" , &a , &b);
		a-- , b--;
		add_edge(a , b);
		add_edge(b , a);		
	}
}

int time;

void dfs(int u)
{
	node *t = list[u];
	enter[u] = ++time;
	low[u] = enter[u];

	while(t->next != NULL)
	{
		t = t->next;
		if(!enter[t->v])		
		{
			father[t->v] = u;
			dfs(t->v);
			t->dir = 1;			
		}
		if(t->v != father[u])
		{
			low[u] = low[u] < low[t->v] ? low[u] : low[t->v];
		}
	}
}

void solve()
{
	memset(enter , 0 , sizeof(enter));
	time = 0;

	int i;
	for(i=0; i<n; i++)
		if(!enter[i])
		{
			dfs(i);
		}
	
	node* t;

	for(i=0; i<n; i++)
	{
		t = list[i];
		while(t->next != NULL)
		{
			t = t->next;
			if(t->dir)
			{
				printf("%d %d\n" , i + 1 , t->v + 1);
				if(low[t->v] >= enter[t->v]) printf("%d %d\n" , t->v + 1 , i + 1);
			}
			else if (enter[t->v] < enter[i] && t->v != father[i]) printf("%d %d\n" , i + 1 , t->v + 1);
		}
	}
	puts("#");
}

int main()
{
//	freopen("in.txt" , "r" , stdin);
	
	int T , t;
	scanf("%d" , &T);
	
	for(t=0; t<T; t++)
	{
		if(t) putchar('\n');
		int caseno = 0;
		while(scanf("%d%d", &n , &m) , n)
		{
			init();
			printf("%d\n\n" , ++caseno);
			solve();
		}
	}
	
	return 0;
}
