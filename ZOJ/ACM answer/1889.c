#include <stdio.h>
int main()
{
    int a;
    int h,t;
    while(1)
    {
        if(scanf("%d",&a)==EOF) break;
        h=1;
        t=1;
        while(1)
        {
            t=t%a;
            if(t%a==0) break;
            t=t*10+1;
            h++;
        }
        printf("%d\n",h);
    }
    return 0;
}
