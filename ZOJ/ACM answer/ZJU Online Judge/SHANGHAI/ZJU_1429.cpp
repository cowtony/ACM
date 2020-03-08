#include <stdio.h>
#include <string.h>

int n;
struct point
{
    int x , y;
} list[55];

bool mark[55];

void init()
{
    int i , k;
    scanf("%d" , &n);
    for(i=0; i<n; i++)
    {
        scanf("%d%d%d" , &k , &list[i].x , &list[i].y);
    }
}

int multiply(const point& a , const point& b , const point& c)
{
    return (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
}

int dist(const point& a , const point& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve()
{
    printf("%d" , n);

    memset(mark , 0 , sizeof(mark));

    int i , j , k;

    k = 0;
    for(i=1; i<n; i++)
    {
        if(list[i].y < list[k].y || (list[i].y == list[k].y && list[i].x < list[k].x))
        {
            k = i;
        }
    }

    printf(" %d" , k + 1);
    mark[k] = 1;
    
    list[n].x = -1000; list[n].y = list[k].y;

    int prev , curt , next , p;
    prev = n; curt = k;

    for(p=1; p<n; p++)
    {
        next = -1;
        for(i=0; i<n; i++)
        {
            if(!mark[i] && (multiply(list[prev] , list[curt] , list[i]) <= 0))
            {
                if(next < 0 || (multiply(list[curt] , list[i] , list[next]) < 0)
                 || (multiply(list[curt] , list[i] , list[next]) == 0 
                  && dist(list[curt] , list[i]) < dist(list[curt] , list[next])))
                {
                    next = i;
                }
            }
        }
        printf(" %d" , next + 1);
        mark[next] = 1;
        prev = curt; curt = next;
    }

    putchar('\n');
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