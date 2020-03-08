int main()
{
    int point,route;
    int re[10000][3];
    int i,j,k,t;
    int b[51];
    int c[50];
    int m,n,l=0;
    while(1)
    {
        scanf("%d",&point);
        if(point==0) break;
        scanf("%d",&route);
        printf("\n");
        for(i=0;i<route;i++)
            scanf("%d%d%d",&re[i][0],&re[i][1],&re[i][2]);
        for(i=0;i<route-1;i++)
        {
            for(j=i;j<route;j++)
            {
                if(re[i][2]>re[j][2])
                {
                    for(k=0;k<3;k++)
                    {
                        t=re[i][k];
                        re[i][k]=re[j][k];
                        re[j][k]=t;
                    }
                }
            }
        }
        for(i=1;i<=point;i++)
         b[i]=0;
        i=0;m=0;n=0;
        if(point==1) c[l++]=0;
        else
        {
            while(1)
            {
                if(b[re[i][0]]==0||b[re[i][1]]==0) {m=m+re[i][2];b[re[i][0]]=1;b[re[i][1]]=1;n++;}
                if(n==point-1) {c[l++]=m;break;}
                i++;
            }
        }
    }
    for(i=0;i<l;i++)
     printf("%d\n",c[i]);
    getch();
}

