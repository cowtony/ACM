int main()
{
    int a[300][51];
    int b[300][51];
    int i,j,k,m,l,t,p;
    char c;
    char num[100];
    int n[100];
    for(i=0;;i++)
    {
        scanf("%d%*c",&n[i]);
        if(n[i]==0) {k=i-1;break;}
        scanf("%c",&c);
        num[i]=c;
        for(j=0;j<n[i];j++)
        scanf("%d",&a[i][j]);
    }
    for(i=0;i<=k;i++)
    {
        if(num[i]=='P')
        {
            for(j=0;j<n[i];j++)
            {
                m=0;
                for(l=0;l<j;l++)
                if(a[i][j]<a[i][l]) m++;
                b[i][a[i][j]-1]=m;
            }
        }
        else
        {
            for(j=0;j<n[i];j++)
             b[i][j]=-1;
            for(j=0;j<n[i];j++)
            {

                p=0;
                for(l=0;l<n[i];l++)
                {
                    if(b[i][l]==-1) p++;
                    if(p==a[i][j] +1) {b[i][l]=j+1;break;}
                }
            }
        }
    }
    for(i=0;i<=k;i++)
    {
        for(j=0;j<n[i];j++)
        {printf("%d",b[i][j]);
         if(j<n[i]-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

