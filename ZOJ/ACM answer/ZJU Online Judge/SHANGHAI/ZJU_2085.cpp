#include <stdio.h>
#include <string.h>

int n;
double p , q;
double f1[52];
double f2[52];

double calc()
{
    if(p == 0) return 0;
    if(p == 1) return 1;
    if(p == 0.5) return 0.5;
    if(n == 1) return p;

    f1[0] = f2[0] = 1;
    f1[1] = 1 / p; f2[1] = 1 / q;    
    for(int i=2; i<=n; i++)
    {
        f1[i] = ( f1[i-1]  - f1[i-2] * q ) / p;
        f2[i] = ( f2[i-1]  - f2[i-2] * p ) / q;
    }
    
    double x = 1 / f1[n];
    double y = 1 / f2[n];
    
    return x / (x + y);
}

int main()
{
    while(scanf("%d" , &n) > 0)
    {
        scanf("%lf" , &p);
        q = 1 - p;
        
        printf("%.6lf\n" , calc());
    }

    return 0;
}