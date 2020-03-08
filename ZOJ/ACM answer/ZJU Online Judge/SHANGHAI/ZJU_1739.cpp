#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxn 101

int N;
struct point
{
    int x , y;
} List[maxn];

int p , r;

void Init()
{
    p = 10000000;
    r =-10000000; 
    for(int i=0; i<N; i++)
    {
        scanf("%d%d" , &List[i].x , &List[i].y);
        if(List[i].y < p) p = List[i].y;
        if(List[i].y > r) r = List[i].y; 
    }
}

int ret;

struct Cross
{
    double a , b , mid;
} c[maxn];

int m;

bool operator < (const Cross& a , const Cross& b)
{
    return a.mid < b.mid;
}

void Process_Line(int Level)
{
    int i , j;
    m = 0;
    for(i=0; i<N; i++)
    {
        j = (i + 1) % N;
        if(List[i].y == List[j].y) continue;
        if(min(List[i].y , List[j].y) <= Level && max(List[i].y , List[j].y) > Level)
        {
            c[m].a = List[i].x + (double)(List[j].x - List[i].x)
             * (Level - List[i].y) / (List[j].y - List[i].y);
            c[m].b = List[i].x + (double)(List[j].x - List[i].x)
             * (Level + 1 - List[i].y) / (List[j].y - List[i].y);
            c[m].mid = (c[m].a + c[m].b) / 2.0;
            m++;
        }
    }

    sort(c , c+m);

    double left = -1000000000.0;

    for(i=0; i<m; )
    {
        ret += max(ceil(max(c[i+1].a , c[i+1].b)) , left) - max(floor(min(c[i].a , c[i].b)) , left);
        left = max(ceil(max(c[i+1].a , c[i+1].b)) , left);
        i += 2;
    }
}

void Solve()
{
    ret = 0;
    for(int Level = p; Level < r; Level++)
    {
        Process_Line(Level);
    }
    printf("%d\n" , ret);
}

int main()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);

    while(1)
    {
        scanf("%d" , &N);
        if(N == 0) break;

        Init();
        Solve();
    }
    
    return 0;
}
