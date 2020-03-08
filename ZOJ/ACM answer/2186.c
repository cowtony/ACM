#include <stdio.h>
int main()
{
    int tem[3];
    int i;
    int k=168;
    for(i=0;i<3;i++)
    {
        scanf("%d",&tem[i]);
        if(tem[i]<=k) {k=tem[i];break;}
    }
    for(i=0;i<3;i++)
    {
        if(tem[i]<=k) {k=tem[i];break;}
    }
    if(k==168) printf("NO CRASH\n");
    else printf("CRASH %d\n",k);
    return 0;
}

