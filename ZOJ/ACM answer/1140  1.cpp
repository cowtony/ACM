#include<string>
#include<iostream>
using namespace std;
const int N = 300;
bool a[N][N], visited[N];
int xm[N], ym[N];
int n, m;

bool DFS( int u )
{
         int v;
         for ( v = 1; v <= m; v++ )
                if ( !visited[v] && a[u][v] )
                {
                       visited[v] = 1;
                       if ( ym[v] == -1 || DFS(ym[v]) )
                       {
                                 xm[u] = v;
                                 ym[v] = u;
                                 return true;
                         }
              }
        return false;
}

int main ()
{
         int test;
         scanf("%d", &test);
         while( test-- )
         {
                scanf("%d%d", &n, &m);
                int i, j, k1, k2, cot = 0;
                memset(a,   0,   sizeof(a) );
                memset(xm, -1, sizeof(xm) );
                memset(ym, -1, sizeof(ym) );
                for ( i = 0; i < n; i++ )
                {
                       scanf("%d", &k1);
                       for ( j = 0; j < k1; j++ )
                       {
                               scanf("%d", &k2);
                               a[i][k2] = 1;
                       }
                }

                for ( i = 0; i < n; i++ )
                         if ( xm[i] == -1 )
                         {
                                  memset(visited, 0, sizeof(visited));
                                  cot += DFS( i );
                          }
               if ( cot == n ) printf("YES\n");
               else printf("NO\n");
         }
         return 0;
}
/*

#include<iostream>
using namespace std;
int links[301];
int cover[301];
int num[301];
int data[301][301];
int  finds(int x)
{
	for(int i=0;i!=num[x];i++)
	{
		if(!cover[data[x][i]])
		{
			int p=links[data[x][i]];
			links[data[x][i]]=x;
			cover[data[x][i]]=1;
			if(p==0||finds(p))
				return 1;
			links[data[x][i]]=p;
		}
	}
	return 0;
}
int main()
{
	int cases,m,n,p;
	cin>>cases;
	int i;
	for(int t=0;t!=cases;t++)
	{
		cin>>p>>n;
		for(i=1;i<=p;i++)
		{
			cin>>num[i];
			for(int j=0;j!=num[i];j++)
			{
				cin>>data[i][j];
			}
		}
		memset(links,0,sizeof(links));
		for( i=1;i<=p;i++)
		{
			memset(cover,0,sizeof(cover));
			finds(i);
		}
		int r=0;
		for( i=1;i<=n;i++)
		{
			if(links[i]!=0)
				r++;
		}
		if(r==p)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
*/