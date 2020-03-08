//147303 2003-05-11 11:07:34 Time Limit Exceeded 1234 C++ 00:10.00 512K just for play 
//147314 2003-05-11 11:13:46 Time Limit Exceeded 1234 C++ 00:10.00 512K just for play 
#include<stdio.h>

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	int nn;
	scanf("%d",&nn);
	while(nn--)
	{
		int k,n;
		scanf("%d%d",&k,&n);
		int i,j,t;
		int len[5001];
		for(i=0;i<n;i++)	scanf("%d",&len[i]);
		int val[2][5001];
		int need[2][5001];
		int last[2][5001];
		int min=50000,beg;
		for(i=0;i<n-1;i++)
		{
			if(len[i+1]-len[i]<min){beg=i+1;min=len[i+1]-len[i];}
			val[0][i+1]=min*min;
			last[0][i+1]=beg;
			if(beg==i+1)	need[0][i+1]=1;
			else	need[0][i+1]=0;
		}
		int pt=1;
		for(t=1;t<k+8;t++)
		{
			for(i=2*t-1;i<n-1;i++)				
			{
				min=50000;
				for(j=last[1-pt][i]+1;j<n-1;j++)
				{										
					if(len[j+1]-len[j]<min){min=len[j+1]-len[j];beg=j+1;}
					int t_val=val[1-pt][i]+min*min;
					if(i==2*t-1||t_val<val[pt][j+1])
					{
						val[pt][j+1]=t_val;
						last[pt][j+1]=beg;
						int t_t=beg-last[1-pt][i]-2;
						if(t_t>need[1-pt][i])
						{
							if(j+1==beg)	need[pt][j+1]=1;
							else	need[pt][j+1]=0;
						}
						else{
							need[pt][j+1]=need[1-pt][i]-t_t+1-(j+1-beg);
							if(need[pt][j+1]<0)	need[pt][j+1]=0;
						}
					}
				}
			}
			pt=1-pt;
		}

		pt=1-pt;
		min=-1;
		for(i=2*t-1;i<n;i++)		
			if(i+need[pt][i]<n&&(min<0||val[pt][i]<min))
				min=val[pt][i];
		printf("%d\n",min);
	}
	return 0;
}
		



		
