//148293 2003-05-11 23:11:51 Wrong Answer 1234 C++ 00:01.18 484K just for play 
//148295 2003-05-11 23:22:45 Wrong Answer 1234 C++ 00:01.69 520K just for play 
//148312 2003-05-11 23:47:43 Wrong Answer 1234 C++ 00:01.17 484K just for play 

#include<stdio.h>
#include<string.h>

inline int cal(int fir,int sec)
{
	return ((sec-fir)*(sec-fir));
}
int main()
{
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int nn;
	scanf("%d",&nn);
	while(nn--)
	{
		int k,n;
		scanf("%d%d",&k,&n);
		int i,j;
		int len[5001];
		for(i=1;i<=n;i++)	scanf("%d",&len[i]);
		int best[2][5001];
		int need[2][5001];
		memset(best,0,sizeof(best));
		memset(need,0,sizeof(need));
		int *up,*down,*temp;
		int *up_n,*down_n,*temp_n;
		down=best[0];up=best[1];
		down_n=need[0];up_n=need[1];
		for(i=1;i<=k+8;i++)
		{
		
			temp=up;up=down;down=temp;
			temp_n=up_n;up_n=down_n;down_n=temp_n;
			down[2*i]=up[2*i-2]+cal(len[2*i],len[2*i-1]);
			down_n[2*i]=up_n[2*i-2]+1;
			for(j=2*i+1;j<=n;j++)
			{
				int t_val=up[j-2]+cal(len[j],len[j-1]);
				if(t_val<down[j-1])
				{
					down[j]=t_val;
					down_n[j]=up_n[j-2]+1;
				}
				else
				{
					down[j]=down[j-1];
					if(down_n[j-1]>0)	down_n[j]=down_n[j-1]-1;
					else	down_n[j]=0;
				}
			}
/*
			for(j=1;j<=n;j++)
			{
				printf("%d ",down[j]);
				if(j%10==0)	printf("\n");
			}
			printf("\n\n");
			for(j=1;j<=n;j++)
			{
				printf("%d ",down_n[j]);
				if(j%10==0)	printf("\n");
			}
			printf("\n\n");
*/
		}
		int min=-1;
		for(i=2*(k+8);i<=n;i++)
			if(i+down_n[i]<=n&&(min<0||min>down[i]))
				min=down[i];
		printf("%d\n",min);
	}
	return 0;
}

		



