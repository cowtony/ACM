#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define maxn 10001
int n , m;

vector<int> son[maxn];
int size[maxn];
vector<int> query[maxn];
int cnt[maxn];
bool mark[maxn];
bool isroot[maxn];
int parent[maxn];

void init()
{
	memset(isroot , 1 , sizeof(isroot));

	char p;
	int u , i , j , k , a , b;
	for(i=0; i<n; i++)
	{
		cin >> u >> p >> p;
		cin >> size[u] >> p;
		son[u].clear();

		for(j=0; j<size[u]; j++)
		{
			cin >> k;
			son[u].push_back(k);
			isroot[k] = 0;
		}
	}
	cin >> m;

	for(i=1; i<=n; i++)
		query[i].clear();
	for(i=0; i<m; i++)
	{
		cin >> p >> a >> p >> b >> p;
		query[a].push_back(b);
		query[b].push_back(a);
	}
}

int find(int u)
{
	if(parent[u] != u)
	{
		parent[u] = find(parent[u]);
	}
	return parent[u];
}

void LCA(int u)
{	
	parent[u] = u;

	int i;
	for(i=0; i<size[u]; i++)
	{
		LCA(son[u][i]);
		parent[son[u][i]] = u;
	}

	mark[u] = 1;

	for(i=0; i<query[u].size(); i++)
	{
		if(mark[query[u][i]])
		{
			cnt[find(query[u][i])]++;
		}
	}
}

void solve()
{
	memset(cnt , 0 , sizeof(cnt));
	memset(mark , 0 , sizeof(mark));

	int i;
	for(i=1; i<=n; i++)
		if(isroot[i])
		{
			LCA(i);
			break;
		}

	for(i=1; i<=n; i++)
	{
		if(cnt[i] == 0) continue;
		cout << i << ":" << cnt[i] << endl;		
	}
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	while(cin >> n)
	{
		init();
		solve();
	}

	return 0;
}