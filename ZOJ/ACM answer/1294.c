int main()
{
    int cas[100][2];
    int i,j;
    int b;
    for(i=0;;i++)
    {
        scanf("%d%d",&cas[i][0],&cas[i][1]);
        if(cas[i][0]==0) break;
    }
    for(j=0;j<i;j++)
    {
        printf("Hole #%d\n",j+1);
        if(cas[j][1]==1) printf("Hole-in-one.\n\n");
        else
        {
            b=cas[j][1]-cas[j][0];
            switch(b)
            {
                case -3:printf("Double Bagle.\n\n");break;
                case -2:printf("Eagle.\n\n");break;
                case -1:printf("Birdie.\n\n");break;
                case 0:printf("Par.\n\n");break;
                case 1:printf("Bogey.\n\n");break;
                default:printf("Double Bogey.\n\n");break;
           }
        }
    }
    return 0;
}

