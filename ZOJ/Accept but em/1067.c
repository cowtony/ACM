#include <math.h>
int main()
{
    long a[100][3];
    int i,j,m,k;
    long t,min,l;
    for(i=0;;i++)
    {
        scanf("%ld%ld%ld",&a[i][0],&a[i][1],&a[i][2]);
        if(a[i][0]==-1&&a[i][1]==-1&&a[i][2]==-1)
        {m=i;break;}
    }
     for(j=16;j<m;j++)
     {  min=3276;
        for(i=0;i<16;i++)
        {
            t=(a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1])+(a[i][2]-a[j][2])*(a[i][2]-a[j][2]);
            l=sqrt(t);
            if(min>l) {min=l;k=i;}
        }
        printf("(%ld,%ld,%ld) maps to (%ld,%ld,%ld)\n",a[j][0],a[j][1],a[j][2],a[k][0],a[k][1],a[k][2]);
     }
    return 0;

}
