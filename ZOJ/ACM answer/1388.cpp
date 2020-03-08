//108325 2003-04-05 23:06:01 Wrong Answer 1388 C++ 00:00.04 476K Century Ghost 
//108676 2003-04-06 09:25:20 Wrong Answer 1388 C++ 00:00.03 420K Century Ghost 
//108708 2003-04-06 10:01:45 Wrong Answer 1388 C++ 00:00.03 460K Century Ghost 
//121294 2003-04-15 12:22:30 Accepted 1388 C++ 00:00.04 420K just for play 
#include<stdio.h>

const int maxnum=10001;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int nn;
	scanf("%d",&nn);
	while(nn--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int i;
		int son[maxnum];

		for(i=1;i<=n;i++)	son[i]=2;
		son[1]=0;

		int fir,sec;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&fir,&sec);
			if(fir==1)
			{
				if(son[sec])	son[sec]--;
			}
			else
			{
				if(son[fir]==2)	
				{
					if(son[sec])	son[sec]--;
				}
				else
				{
					if(son[sec])
					{
						son[fir]=son[sec];
						son[sec]--;
					}
				}
			}
		}
		int count=0;
		for(i=1;i<=n;i++)
			count+=son[i];
		printf("%d\n",count);
	}
	return 0;
}