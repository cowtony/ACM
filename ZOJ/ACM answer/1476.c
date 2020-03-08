#include <stdio.h>
int main()
{
    unsigned d,s;
    int i,j,n;
    for(i=0;;i++)
    {
        scanf("%d%d",&s,&d);
        if(d==0&&s==0) break;
        n=0;
        for(j=0;j<60;j++)
        {
            s=(s*d+s)%60;
            if(s==0) break;
        }
       if(j==60) printf("Impossible\n");
       else printf("%d\n",j+1);
    }
    return 0;
}
