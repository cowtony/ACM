#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 110
#define maxm 8000

int n;
int deg[maxn] , dist[maxn];
int m;
int list[maxm];
int p;
int g[maxn][100] , lab[maxn];

void Init()
{
    n = m = 0;
    
    while(1)
    {
        scanf("%d" , &list[m]);
        if(list[m] == 0) break;
        if(list[m] > 0)
        {
            deg[n++] = list[m];
        }
        m++;
    }
}

int path[maxn];
int curt;

void visit(int u , int d)
{    
    dist[u] = d;
    p++; // skip deg
    
    path[d] = u;    
    
    while(lab[u] < deg[u])
    {
        if(list[p] > 0)
        {
            g[u][lab[u]++] = ++curt;
            g[curt][lab[curt]++] = u;
            visit( curt , d + 1 );
        }                    
        else
        {
            g[u][lab[u]++] = path[d + list[p]];
            g[path[d + list[p]]][lab[path[d + list[p]]]++] = u; 
            p++;         
        }
    }
}

void Solve()
{
    curt = 0; p = 0;
    memset(lab , 0 , sizeof(lab));
    visit( 0 , 0 );
    
    int i , j;
    for(i=0; i<n; i++)
    {
        printf("%d" , i + 1);
        sort(g[i] , g[i] + deg[i]);
        for(j=0; j<deg[i]; j++)
            printf(" %d" , g[i][j] + 1);
        putchar('\n');
    }
}

int main()
{
//    freopen("in.txt" , "r" , stdin);
    
    int T;
    scanf("%d" , &T);
    
    while(T--)
    {
        Init();
        Solve();
    }
        
    return 0;
}
