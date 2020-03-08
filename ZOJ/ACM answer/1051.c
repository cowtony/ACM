int main()
{
    int D[16];
    int sq[22][22]={0},sp[20][20];
    int i,j,m,d,c;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&d);
        for(i=0;i<16;i++)
            scanf("%d",&D[i]);
        for(i=1;i<21;i++)
            for(j=1;j<21;j++)
                scanf("%d",&sq[i][j]);
     while(d--)
      {
        for(i=1;i<21;i++)
            for(j=1;j<21;j++)
            {
                m=sq[i][j]+sq[i-1][j]+sq[i+1][j]+sq[i][j-1]+sq[i][j+1];
                sp[i-1][j-1]=sq[i][j]+D[m];
                if(sp[i-1][j-1]>3) sp[i-1][j-1]=3;
                else if(sp[i-1][j-1]<0) sp[i-1][j-1]=0;
            }
        for(i=1;i<21;i++)
             for(j=1;j<21;j++)
             sq[i][j]=sp[i-1][j-1];
      }
        for(i=1;i<21;i++)
        {
          for(j=1;j<21;j++)
          {if(sq[i][j]==3) printf("#");
           else if(sq[i][j]==2) printf("X");
           else if(sq[i][j]==1) printf("!");
           else printf(".");
          }
         printf("\n");
        }
        if(c>0) printf("\n");

    }
    return 0;
}
