#include <stdio.h>
#include <string.h>
#include <math.h>

int p , n;
double ans;

int gcd(int a , int b)
{
    return b == 0 ? a : gcd(b , a % b);
}

void solve()
{
    int a , b;
    int c , d;
    double ab , cd;
    double x , y;

    ans = sqrt((double)p);
    ab = 0; cd = p * 2;

    for(y=1; y<=n; y++)
    {
        x = floor(y * ans);
        if(x < 1) x = 1;
        if(x > n) x = n;
        if(x / y <= ans && x / y > ab)
        {
            ab = x / y;
            a = x; b = y;
        }
        x = ceil(y * ans);
        if(x < 1) x = 1;
        if(x > n) x = n;
        if(x / y >= ans && x / y < cd)
        {
            cd = x / y;
            c = x; d = y;
        }
    }

    printf("%d/%d %d/%d\n" , c / gcd(c , d) , d / gcd(c , d) , a / gcd(a , b) , b / gcd(a , b));
}

int main()
{
    while(1)
    {
        scanf("%d%d" , &p , &n);
        if(p == 0) break;

        solve();
    }
    
    return 0;
}
