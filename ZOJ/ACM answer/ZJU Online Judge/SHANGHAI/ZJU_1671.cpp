#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n , m;
int g[10][10];
int x , y , x1 , y1;

void Init()
{
    int i , j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d" , &g[i][j]);
            if(g[i][j] == 2)
            {
                x = i , y = j;
            }
            if(g[i][j] == 3)
            {
                x1 = i , y1 = j;
            }
        }
    }
}

bool f[10][10][10];
struct Q_Type
{
    int x , y , ph , len;
} Q[10 * 10 * 10];
int Head , Tail;

bool push(int x , int y , int ph , int len)
{
    if(ph == 0) return 0;
    if(x == x1 && y == y1)
    {
        printf("%d\n" , len);
        return 1;
    }
    if(ph == 1) return 0;    
    if(!f[x][y][ph])
    {
        f[x][y][ph] = 1;
        ++Tail;
        Q[Tail].x = x;
        Q[Tail].y = y;
        Q[Tail].ph = ph;
        Q[Tail].len = len;
    }
    return 0;
}

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1, 0 , 0 };

inline bool valid(int x , int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y];
}

void Solve()
{
    memset(f , 0 , sizeof(f));
    Head = 0; Tail = -1;

    push(x , y , 6 , 0);

    int i;

    while(Head <= Tail)
    {
        for(i=0; i<4; i++)
        {
            if(valid(Q[Head].x + dx[i] , Q[Head].y + dy[i]))
            {
                if(push(Q[Head].x + dx[i] , Q[Head].y + dy[i] ,
                g[Q[Head].x + dx[i]][Q[Head].y + dy[i]] == 4 ? 6 : Q[Head].ph - 1 ,
                Q[Head].len + 1))
                    return;
            }
        }
        Head++;
    }

    puts("-1");
}

int main()
{
//    freopen("in.txt" , "r" , stdin);
    while(1)
    {
        scanf("%d%d" , &m , &n);
        if(!n) break;

        Init();
        Solve();
    }

//    system("pause");
    return 0;
}
