int main()
{
    long x[4],y[4];
    long b[6];
    int i,j,k,m,n,l;
    int cas;
    int a[100];
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        for(j=0;j<4;j++)
            scanf("%ld%ld",&x[j],&y[j]);
        m=0;
        for(j=0;j<3;j++)
        {
            for(k=j+1;k<4;k++)
            {
                b[m++]=(y[j]-y[k])*(y[j]-y[k])+(x[j]-x[k])*(x[j]-x[k]);
            }
        }
        n=1;l=1;
        for(j=1;j<m;j++)
        {
           if(b[j]==b[0]) {n++;b[j]=-1;}
        }
        if(n!=4&&n!=2) {a[i]=0;continue;}
        else
        {
            for(j=1;j<m;j++)
            {
                if(b[j]!=-1) break;
            }
            for(k=j+1;k<m;k++)
            {
                if(b[k]==b[j]) l++;
            }
        }
        if(l!=4&&l!=2) {a[i]=0;continue;}
        else if((l+n)!=6) {a[i]=0;continue;}
        else a[i]=1;
    }
    for(k=0;k<cas;k++)
    {  if(a[k]==1) printf("Case %d:\nYes\n",k+1);
       else printf("Case %d:\nNo\n",k+1);
       if(k<cas-1) printf("\n");
    }
    return 0;
}


