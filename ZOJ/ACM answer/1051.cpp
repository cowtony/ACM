 //84510 2003-03-07 23:57:01 Accepted 1051 C++ 00:00.00 384K Century Ghost
 #include<stdio.h>

 int main()
 {
	int tt;int i;const int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
	scanf("%d",&tt);
	for(i=0;i<tt;i++)
	{
		if(i)	printf("\n");
		int n;int flag[22][22];int j,t;int d[16];
		scanf("%d",&n);
		for(j=0;j<16;j++)	scanf("%d",&d[j]);
		for(j=1;j<21;j++)
			for(t=1;t<21;t++)	scanf("%d",&flag[j][t]);
		for(j=0;j<22;j++) {flag[0][j]=0;flag[j][0]=0;flag[21][j]=0;flag[j][21]=0;}
		int tempflag[22][22];int tm;
		for(j=0;j<n;j++)
		{
			for(t=0;t<22;t++)
				for(tm=0;tm<22;tm++)	tempflag[t][tm]=flag[t][tm];
			int changed=0;
			for(t=1;t<21;t++)
				for(tm=1;tm<21;tm++)
				{
					int total=tempflag[t][tm];
					for(int tt=0;tt<4;tt++)
						total+=tempflag[t+dir[tt][0]][tm+dir[tt][1]];
					flag[t][tm]=tempflag[t][tm]+d[total];
					if(d[total]!=0)	changed=1;
					if(flag[t][tm]>3)	flag[t][tm]=3;
					if(flag[t][tm]<0)	flag[t][tm]=0;
				}

			if(!changed)	break;
		}
		char outch[4]={'.','!','X','#'};
		for(j=1;j<21;j++)
			for(t=1;t<21;t++)
			{	printf("%c",outch[flag[j][t]]);
				if(t==20)	printf("\n");

			}
	}
	return 0;
 }





