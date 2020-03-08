#include <stdio.h>
int main()
{
    long int a;
    long int b,temp;
    int ha,li;
    while(1)
    {
        if(scanf("%ld",&a)==EOF) break;
        b=0;
        temp=0;
        while(b<a)
        {
            temp++;
            b+=temp;
        };
        if(temp%2!=0)
        {
            ha=b-a+1;
            li=temp+1-ha;
            printf("TERM %ld IS %d/%d\n",a,ha,li);
        }
        else
        {
            li=b-a+1;
            ha=temp+1-li;
            printf("TERM %ld IS %d/%d\n",a,ha,li);
        }
    }
    return 0;
}
