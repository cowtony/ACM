#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 210

int n;
int deg[maxn];
int list[maxn][maxn];

void init()
{
    scanf("%d" , &n);
    
    int i , k;
    for(i=1; i<=n; i++)
    {
        scanf("%d%d" , &k , &deg[i]);
        for(k=0; k<deg[i]; k++)
        {
            scanf("%d" , &list[i][k]);
        }
    }
}

int dp(int u)
{
    if(deg[u] == 0) return 1;
    int *p = new int[deg[u] + 1];
    int i , k , max;

    for(i=0; i<deg[u]; i++)
    {
        p[i] = dp(list[u][i]);
    }

    sort(p , p + deg[u]);

    max = 0;
    for(i=deg[u]-1 , k = 0;  i>=0; i-- , k++)
    {
        if(k + p[i] > max) max = k + p[i];
    }

    return max;
}

void solve()
{
    printf("%d\n" , dp( 1 ));
}

int main()
{
    freopen("in.txt" , "r" , stdin);

    int T;

    scanf("%d" , &T);

    while(T--)
    {
        init();
        solve();
    }

    return 0;
}
