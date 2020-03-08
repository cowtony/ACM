#include <stdio.h>
int main()
{
    int a[10][925][6];
    int k,s[13],games[100];
    int i,j,l=0,m,n,p,q,u;
    while(1)
    {
        scanf("%d",&k);
        if(k==0) break;
        for(i=0;i<k;i++)
        {
            scanf("%d",&s[i]);
        }
        u=0;
        for(i=0;i<k-5;i++)
        {
            for(j=i+1;j<k-4;j++)
            {
                for(m=j+1;m<k-3;m++)
                {
                    for(n=m+1;n<k-2;n++)
                    {
                        for(p=n+1;p<k-1;p++)
                        {
                            for(q=p+1;q<k;q++)
                            {
                                a[l][u][0]=s[i];
                                a[l][u][1]=s[j];
                                a[l][u][2]=s[m];
                                a[l][u][3]=s[n];
                                a[l][u][4]=s[p];
                                a[l][u][5]=s[q];
                                u++;
                            }
                        }
                   }
               }
            }
        }
            games[l++]=u;
    }
    for(i=0;i<l;i++)
    {
         for(j=0;j<games[i];j++)
         {
             printf("%d %d %d %d %d %d\n",a[i][j][0],a[i][j][1],a[i][j][2],a[i][j][3],a[i][j][4],a[i][j][5]);
         }
         if(i<l-1) printf("\n");
    }
    return 0;
}



