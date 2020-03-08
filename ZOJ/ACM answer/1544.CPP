//147643 2003-05-11 15:11:01 Wrong Answer 1544 C++ 00:00.09 580K just for play 
//147660 2003-05-11 15:22:41 Wrong Answer 1544 C++ 00:00.16 584K just for play 
//147765 2003-05-11 16:08:10 Wrong Answer 1544 C++ 00:00.00 580K just for play 


//use bellmem-fall algorithm
//but perhaps didn't handle correctly with the float number
//.............


#include<stdio.h>
#include<string.h>

const double epsilon=1.0e-10;

int main()
{
//	freopen("in.txt","r",stdin);

	int n,m,s;double cur;
	while(scanf("%d%d%d%lf",&n,&m,&s,&cur)!=EOF)
	{
		double r[101][101];
		double c[101][101];
		int flag[101][101];
		memset(flag,0,sizeof(flag));
		int i,j;int fir,sec;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&fir,&sec);
			scanf("%lf%lf",&r[fir][sec],&c[fir][sec]);
			scanf("%lf%lf",&r[sec][fir],&c[sec][fir]);
			flag[fir][sec]=1;flag[sec][fir]=1;
		}
		double money[101];
		for(i=1;i<=n;i++)	money[i]=0.0;
		money[s]=cur;
		bool found=false;
		int visit[101];
		memset(visit,0,sizeof(visit));
		visit[s]=1;
		while(1)
		{
			bool changed=false;
			for(i=1;i<=n;i++)
			{
				if(visit[i])
				{
					for(j=1;j<=n;j++)
					{
						if(flag[i][j])
						{
							double t_money=(money[i]-c[i][j])*r[i][j];
							if(visit[j])
							{
								if(t_money>money[j]+epsilon)	{found=true;break;}
							}
							else if(t_money>money[j])
							{
								visit[j]=1;changed=true;money[j]=t_money;
							}

						}							
					}
					if(j<=n)	break;
				}
			}
			if(i<=n)	break;
			if(!changed)	break;
		}
		if(found)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}


						




			
			
