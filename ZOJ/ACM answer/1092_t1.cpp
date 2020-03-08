 #include<stdio.h>
 #include<string.h>

 int main()
 {

	int m,n;int count=0;
	while(1)
	{
		scanf("%d",&n);

		if(n==0)	break;
		count++;
		int i,j;int t,k;
		char curr[31][20];
		float	chg[31][31];
		for(i=0;i<n;i++)
			scanf("%s",curr[i]);
		scanf("%d",&m);
		char from[20],to[20];float temp;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)	chg[i][j]=-1;
		for(i=0;i<n;i++)	chg[i][i]=1.0;
		for(j=0;j<m;j++)
		{
			scanf("%s %f %s",from, &temp,to);

			for(t=0;t<n;t++)
				if(strcmp(from,curr[t])==0)	break;
			for(k=0;k<n;k++)
				if(strcmp(to,curr[k])==0)	break;
			chg[t][k]=temp;
		}

		int flag=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
				{
					for(t=0;t<n;t++)
					{
						if(chg[j][t]<0||chg[t][k]<0)	continue;
						float temp=chg[j][t]*chg[t][k];
						if(temp>chg[j][k])	chg[j][k]=temp;
					}
				}
			for(j=0;j<n;j++)
				if(chg[j][j]>1.0){flag=1;break;}
			if(flag)	break;
		}
		printf("Case %d: ",count);
		if(flag)	printf("Yes\n");
		else		printf("No\n");
	}
	return 0;
 }








