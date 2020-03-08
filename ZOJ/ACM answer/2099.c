#include <stdio.h>
int main()
{
    long a[100][2];
    long cas[200][4];
    long maxx,maxy,minx,miny;
    int i,j,k=0;
    while(1)
    {
        scanf("%ld%ld",&a[0][0],&a[0][1]);
        if(a[0][0]==0&&a[0][1]==0) break;
        for(i=1;;i++)
        {
            scanf("%ld%ld",&a[i][0],&a[i][1]);
            if(a[i][0]==0&&a[i][1]==0) break;
        }
        maxx=minx=a[0][0];
        maxy=miny=a[0][1];
        for(j=1;j<i;j++)
        {
            if(a[j][0]>maxx) maxx=a[j][0];
            else if(a[j][0]<minx) minx=a[j][0];
            if(a[j][1]>maxy) maxy=a[j][1];
            else if(a[j][1]<miny) miny=a[j][1];
        }
        cas[k][0]=minx;cas[k][1]=miny;
        cas[k][2]=maxx;cas[k][3]=maxy;
        k++;
    }
    for(i=0;i<k;i++)
    {
        printf("%ld %ld %ld %ld\n",cas[i][0],cas[i][1],cas[i][2],cas[i][3]);
    }
    return 0;
}

