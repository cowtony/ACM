#include <stdio.h>
#include <string.h>
#include <math.h>

int n;
struct point
{
    double x , y;
}a , b , c;

void init()
{
    scanf("%lf%lf" , &a.x , &a.y);
    scanf("%lf%lf" , &b.x , &b.y);
    scanf("%lf%lf" , &c.x , &c.y);
}

void line(double& a , double& b , double& c , point& p , point& q)
{
    a = + (p.x - q.x) * 2;
    b = + (p.y - q.y) * 2;
    c = - (p.x - q.x) * (p.x + q.x) - (p.y + q.y) * (p.y - q.y);
}

void solve()
{
    double a1 , b1 , c1;
    line(a1 , b1 , c1 , a , b);
    double a2 , b2 , c2;
    line(a2 , b2 , c2 , a , c);

    double x = (c2 * b1 - c1 * b2) / (a1 * b2 - a2 * b1);
    double y = (c2 * a1 - c1 * a2) / (b1 * a2 - b2 * a1);

    double r = sqrt((x-a.x) * (x-a.x) + (y-a.y) * (y-a.y));
    double alpha = acos(0) * 4 / n;
    double theta = atan2(a.y - y , a.x - x);

    double minx , miny , maxx , maxy;
    
    minx = maxx = a.x - x;
    miny = maxy = a.y - y;

    for(int i=0; i<n; i++)
    {
        x = r * cos(theta);
        y = r * sin(theta);

        if(x < minx) minx = x;
        if(x > maxx) maxx = x;
        if(y < miny) miny = y;
        if(y > maxy) maxy = y;

        theta += alpha;
    }

    printf("%.3lf\n" , (maxx - minx) * (maxy - miny));
}

int main()
{
//    freopen("in.txt" , "r" , stdin);

    int Caseno = 0;

    while(1)
    {
        scanf("%d" , &n);
        if(!n) break;
    
        printf("Polygon %d: " , ++Caseno);
        init();
        solve();
    }
    
    return 0;
}