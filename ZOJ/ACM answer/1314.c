#include <stdio.h>
int main()
{
    long a[100][2];
    long i=0,j,k,l,n,m;
    while(scanf("%ld%ld",&a[i][0],&a[i][1])!=EOF)
    {
        i++;
    }
    for(j=0;j<i;j++)
    {
        printf("%10ld",a[j][0]);
        printf("%10ld",a[j][1]);
        k=a[j][0]%a[j][1];
        m=k;n=1;
        while(1)
        {
           m=(m+a[j][0])%a[j][1];
           if(m==k) break;
           n++;
        }
        if(n==a[j][1]) printf("    Good Choice\n\n");
        else printf("    Bad Choice\n\n");
    }
    return 0;
}

