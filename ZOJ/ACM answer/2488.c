int main()
{
    int rope[1001];
    int cas;
    long b[10];
    int ropes,change;
    long max;
    int i,j,k;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        scanf("%d",&ropes);
        for(j=0;j<ropes;j++)
        {
            scanf("%d",&rope[j]);
        }
        for(j=0;j<ropes-1;j++)
        {
            for(k=j+1;k<ropes;k++)
            {
                if(rope[j]<rope[k])
                {
                    change=rope[j];
                    rope[j]=rope[k];
                    rope[k]=change;
                 }
             }
        }
        max=0;
        for(j=0;j<ropes;j++)
        {
            if(max<(rope[j]*(j+1))) max=rope[j]*(j+1);
        }
        b[i]=max;
    }
    for(i=0;i<cas;i++)
    {
        printf("%ld\n",b[i]);
    }
    return 0;
}

