#include <stdio.h>
#include <string.h>

int n , m;
char g[10][10];
short f[10][10][10][10];

void Init()
{
    int i , j;
    int a , b , c , d;
    char s[10];
    
    scanf("%d%d" , &n , &m);
    for(i=0; i<n; i++)
    {
        scanf("%s" , g[i]);
    }

    memset(f , 0 , sizeof(f));
    while(1)
    {
        scanf("%d%d%s%d%d" , &a , &b , s , &c , &d);
        if(a == 0) break;
        a--,b--,c--,d--;
        if(s[0] == 'R')
        {
            f[a][b][c][d] = 1;
        }
        else f[a][b][c][d] = -1;
    }
}

int mark[10][10];
char ans[10][10];
int list[10][10];

bool search(int p , int c)
{
    if(p == m)
    {
        for(int i=0; i<m; i++)
        {
            puts(ans[i]);
        }
        return 1;
        // print
    }
    if(c == n)
    {
        int i , x , y;
        for(i=0; i<n; i++)
        {
            for(x=0; x<n; x++)
                for(y=0; y<m; y++)
                    if(f[i][list[p][i]][x][y] != 0)
                    {
                        if(f[i][list[p][i]][x][y] > 0 && mark[x][y] != p) goto next;
                        if(f[i][list[p][i]][x][y] < 0 && mark[x][y] == p) goto next;
                    }
        }
        next :
        if(i == n) return search(p + 1 , 0);
        return 0;
    }
    else
    {
        for(int i=0; i<m; i++)
            if(mark[c][i] < 0)
            {
                mark[c][i] = p;
                list[p][c] = i;
                ans[p][c] = g[c][i];
                if(search(p , c + 1)) return 1;
                mark[c][i] = -1;
            }
        return 0;
    }
}

void Solve()
{
    memset(ans , 0 , sizeof(ans));
    memset(mark , 0xff , sizeof(mark));
    search(0 , 0);    
}

int main()
{
    freopen("in.txt" , "r" , stdin);

    int T;
    scanf("%d" , &T);

    while(T--)
    {
        Init();
        Solve();
        if(T) putchar('\n');
    }
    
    return 0;
}
