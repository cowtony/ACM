#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N;
char buf[100];
char g[1010][100];
int m , list[1000];

void Init()
{
    gets(buf);
    memset(g , 0 , sizeof(g));
    memset(list , 0 , sizeof(list));
    for(int i=0; i<N; i++)
    {
        gets(g[i]);
    }
}

int p , r , left , right;
int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {1,-1,0,1,-1,0,1,-1};

inline bool valid(int x , int y)
{
    return (x >= 0 && y >= 0 && x < N && g[x][y] == '*');
}

void floodfill(int x , int y)
{
    g[x][y] = ' ';
    for(int i=0; i<8; i++)
    {
        if(valid(x + dx[i] , y + dy[i]))
        {
            floodfill(x + dx[i] , y + dy[i]);
        }
    }
    if(x > r)
    {
        r = x;
        left = 1000;
        right= 0;
    }
    if(x == r)
    {
        if(y < left) left = y;
        if(y > right) right = y;
    }
}

void Solve()
{
    int i , j , k;
    m = 0;
    for(i=0; i<N; i++)
    {
        for(j=0; g[i][j]; j++)
        {
            if(g[i][j] == '*')
            {
                for(k=j+1; g[i][k] == '*'; k++){}
                r = i;
                left = 100; right = 0;
                floodfill(i , j);
                list[m++] = (right - left + 1 + k - j) * (r - i + 1) / 2;
            }
        }
    }

    sort(list , list + m);
    // output

    list[m] = 100000000;
    for(i=0; i<m; )
    {
        p = i + 1;
        while(list[p] == list[i]) p++;
        printf("%d %d\n" , list[i] , p - i);
        i = p;
    }
}

int main()
{
//    freopen("in.txt" , "r" , stdin);

    bool first = 1;

    while(1)
    {
        scanf("%d" , &N);
        if(N == 0) break;

        if(first) first = 0;
        else puts("----------");

        Init();
        Solve();
    }

//   system("pause");
    
    return 0;
} 
