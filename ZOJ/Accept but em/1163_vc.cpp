//108859 2003-04-06 11:26:31 Accepted 1163 C++ 00:00.02 2340K Century Ghost 
#include<stdio.h>


double total[501][501];



int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	int i,j,t;int temp[501];
	for(i=0;i<501;i++)
		temp[i]=i*(i+1)/2;

	for(i=0;i<501;i++)
		for(j=0;j<501;j++)
			total[i][j]=0;
	total[1][1]=1;
	for(i=2;i<501;i++)	total[i][1]=1;
	for(i=2;i<501;i++)
	{
		
		for(j=2;;j++)
		{
			double res=0;
			if(temp[j]>i)	break;
			for(t=1;;t++)
			{
				int left_n=i-j*t;
				if(temp[j-1]>left_n)	break;
				res+=total[left_n][j-1];
			}
			total[i][j]=res;
//			printf("%d---%d===%1.0lf\n",i,j,total[i][j]);
		}
	}

	while(scanf("%d",&n))
	{
		if(n==0)	break;
		int i;double res=0;
		for(i=2;i<501;i++)
		{
			if(total[n][i]==0)	break;
			res+=total[n][i];
		}
		printf("%1.0lf\n",res);
	}
	return 0;
}
		