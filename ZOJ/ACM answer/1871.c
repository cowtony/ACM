#include <stdio.h>
#include <math.h>
int main()
{
    long x,y;
    long length;
    long step;
    long l,t;
    while(scanf("%ld%ld",&x,&y)!=EOF)
    {
        length=y-x;
        step=(long)(sqrt(length+0.25)-0.5);
        l=step;
        t=length-step*(step+1);
        step*=2;
        if(t!=0) step++;
        if(t>l+1) step++;
        printf("%ld\n",step);
    }
    return 0;
}