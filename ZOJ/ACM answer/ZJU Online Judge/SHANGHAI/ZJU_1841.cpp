#include <stdio.h>
#include <string.h>

const int maxn = 1010;
#define prev(k) (((k)+n-1)%n)
#define next(k) (((k)+1)%n)

int n;
struct point
{
    int x , y;
} list[maxn];


void init()
{
    for(int i=0; i<n; i++)
    {
        scanf("%d%d" , &list[i].x , &list[i].y);
        list[i].x *= 2;
        list[i].y *= 2;
    }
}

bool cline(point& a , point& b , point& c)
{
    return (b.x - a.x) * (c.y - a.y) == (b.y - a.y) * (c.x - a.x);
}

inline int dist(point& a , point& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve()
{
    int ret = 0;
    int i , p , r;
    
    point top , mid , pmid;
    bool flag;

    for(i=0; i<n; i++)
    {
        p = prev(i);
        r = next(i);

        mid.x = (list[p].x + list[r].x) / 2;
        mid.y = (list[p].y + list[r].y) / 2;
        
        flag = 1;
        for( ; ; p=prev(p) , r=next(r))
        {
            pmid.x = (list[p].x + list[r].x) / 2;
            pmid.y = (list[p].y + list[r].y) / 2;

            if(!(cline(list[i] , mid , pmid) && dist(list[p] , list[i]) == dist(list[r] , list[i])))
            {
                flag = 0;
                break;
            }            
            if(p == r) break;
            if(prev(p) == r) break;
        }

        if(flag)
        {
            ret++;
        }
    }

    if(n == 3)
    {
        printf("%d symmetry line(s).\n" , ret);
        return;
    }

    for(i=0; i<n; i++)
    {
        p = i; r = next(i);
        top.x = (list[p].x + list[r].x) / 2;
        top.y = (list[p].y + list[r].y) / 2;

        p = prev(p); r = next(r);
        
        mid.x = (list[p].x + list[r].x) / 2;
        mid.y = (list[p].y + list[r].y) / 2;

        flag = 1;
        for( ; ; p=prev(p) , r=next(r))
        {
            pmid.x = (list[p].x + list[r].x) / 2;
            pmid.y = (list[p].y + list[r].y) / 2;

            if(!(cline(top , mid , pmid) && dist(list[p] , top) == dist(list[r] , top)))
            {
                flag = 0;
                break;
            }            
            if(p == r) break;
            if(prev(p) == r) break;
        }

        if(flag)
        {
            ret++;
        }
    }

    printf("%d symmetry line(s).\n" , ret / 2);
}

int main()
{
//    freopen("in.txt" , "r" , stdin);

    int caseno = 0;

    while(1)
    {
        scanf("%d" , &n);
        if(!n) break;

        printf("Polygon #%d has " , ++caseno);

        init();
        solve();
    }
    
    return 0;
}