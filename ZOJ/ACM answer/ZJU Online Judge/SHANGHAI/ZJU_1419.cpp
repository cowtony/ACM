#include <stdio.h>
#include <string.h>

#define maxn 55

struct point
{
    double x , y;
} list[maxn];
int n , m;
int s[maxn];

void init()
{
    scanf("%d" , &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%lf%lf" , &list[i].x , &list[i].y);
    }
}    

void solve()
{
    int k , t , ret , i , j;
    double max = 0 , area;

    scanf("%d" , &k);
    for(t=1; t<=k; t++)
    {
        scanf("%d" , &m);
        for(i=0; i<m; i++)
        {
            scanf("%d" , &s[i]);
        }
        area = 0;
        for(i=0; i<m; i++)
        {
            j = (i + 1) % m;
            area += list[s[i]].x * list[s[j]].y - list[s[i]].y * list[s[i]].x;
        }
        if(area < 0) area = - area;
        if(area > max)
        {
            max = area;
            ret = t;
        }
    }

    printf("%d\n" , ret);
}

int main()
{
    int T;
    scanf("%d" , &T);

    while(T--)
    {
        init();
        solve();
    }
    
    return 0;
} 
