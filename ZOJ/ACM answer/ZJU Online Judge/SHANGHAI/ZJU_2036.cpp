#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

double k , h;
int n;

const int maxn = 110;
const double pi = acos(0) * 2;

struct point
{
    double x , y;
} list[maxn];

struct segment
{
    double p , r;
} s[maxn * 2];
int cnt;

bool operator < (const segment& a , const segment& b)
{
    return a.p < b.p;
}

void init()
{
    scanf("%lf%lf" , &k , &h);
    scanf("%d" , &n);

    for(int i=0; i<n; i++)
    {
        scanf("%lf%lf" , &list[i].x , &list[i].y);
    }
}

void insert_segment(double p , double r)
{
    s[cnt].p = p;
    s[cnt].r = r;
    cnt++;
}

void solve()
{
    int i , j;
    double a , b , t; 
    cnt = 0;

    for(i=0; i<n; i++)
    {
        j = (i + 1) % n;
        a = atan2(list[i].y , list[i].x);
        b = atan2(list[j].y , list[j].x);
        if(a < 0) a += pi * 2;
        if(b < 0) b += pi * 2;
        if(a > b)
        {
            t = a; a = b; b = t;
        }

        if(a + pi < b)
        {
            insert_segment(0 , a);
            insert_segment(b , pi * 2);
        }
        else insert_segment(a , b);
    }

    sort(s , s + cnt);
    double tot = 0;
    double curt = 0;

    for(i=0; i<cnt; i++)
    {
        if(s[i].r <= curt) continue;
        if(s[i].p >= curt)
        {
            curt = s[i].r;
            tot += s[i].r - s[i].p;
        }
        else
        {
            tot += s[i].r - curt;
            curt = s[i].r;
        }
    }

    printf("%.2lf\n" , k * h * tot);
}

int main()
{
    //freopen("in.txt" , "r" , stdin);

    int T;
    scanf("%d" , &T);

    while(T--)
    {
        init();
        solve();
        if(T) putchar('\n');
    }

    return 0;
}