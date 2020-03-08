int main()
{
    int a[1001];
    int i,j,k=1;
    int m,n,pip,win;
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(m==0&&n==0) break;
        for(j=1;j<=1000;j++)
        {
            a[j]=0;
        }
        for(j=0;j<n;j++)
        {
            scanf("%d",&pip);
            a[pip]=1;
        }
        for(i=1;;i++)
        {
            if(a[i]==1) break;
        }
        win=0;
        for(j=i;j<=m*n;j++)
        {
            if(a[j]==1) win++;
            else win--;
            if(win<0) win=0;
        }
        printf("Case %d: %d\n",k++,win);
    }
    return 0;
}


