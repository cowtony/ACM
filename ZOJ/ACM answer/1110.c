#include <stdio.h>
int main()
{
    int a[1000][4];
    int b[1000][3];
    int i=0,j,t;
    while(++i&&scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3])!=EOF);
    for(j=1;j<i;j++)
    {
        t=a[j][3]+12-(a[j][0]+2*a[j][1]);
        if((a[j][2]-a[j][1])==a[j][0])
        {
            b[j][2]=t/3;
            b[j][1]=b[j][2]+a[j][1];
            b[j][0]=b[j][1]+a[j][0];
            if(t%3==1) b[j][0]++;
            else if(t%3==2) {b[j][0]++;b[j][1]++;}
        }
        else
        {
            if(t%3==0) 
            {
                b[j][2]=t/3-1;
                b[j][1]=t/3+a[j][1];
                b[j][0]=t/3+a[j][2];
            }
            else
            {
                b[j][2]=t/3;
                b[j][0]=b[j][2]+a[j][2];
                b[j][1]=a[j][3]+12-b[j][0]-b[j][2];
            }
        }
    }
    for(j=1;j<i;j++)
    {
        printf("%d %d %d\n",b[j][0],b[j][1],b[j][2]);
    }
    return 0;
}

