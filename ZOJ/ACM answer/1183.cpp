//116984 2003-04-11 23:37:42 Time Limit Exceeded 1183 C++ 00:10.00 404K just for play 
//118847 2003-04-13 13:44:19 Time Limit Exceeded 1183 C++ 00:10.00 404K just for play 
//118891 2003-04-13 14:27:50 Accepted 1183 C++ 00:00.71 5328K just for play 
#include<stdio.h>
#include<string.h>

int time[1001];
int total_time[1001];
int cost;int n,len;
int val[1001][1001];
bool flag[1001][1001];
int end_n=0;
int max_state[1001];

int cal(int left,int len)
{
	if(len==left)	return 0;
	if(len-left<=10)	return (-cost);
	else	return (len-left-10)*(len-left-10);
}



int search(int lev,int to)
{
//	printf("%d      %d\n",lev,to);
//	if(flag[lev][to])	return val[lev][to];
	if(flag[lev][to])	return val[lev][to];
	int i;
	for(i=max_state[lev-1];i>=0;i--)
	{
		if(total_time[to]-total_time[i]<=len)
		{
			int next_lev=search(lev-1,i);
			int temval=next_lev+cal(total_time[to]-total_time[i],len);
			if(flag[lev][to]==false||temval<val[lev][to])
				val[lev][to]=temval,flag[lev][to]=true;
		}
		else	break;
	}
//	printf("%d---%d--->%d\n",lev,to,val[lev][to]);
	return val[lev][to];
}
	
	




int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int nn;int t;
	scanf("%d",&nn);
	for(t=0;t<nn;t++)
	{
		if(t)	printf("\n");
		int count=0;
		while(scanf("%d",&n))
		{
			if(n==0)	break;
			if(count)	printf("\n");
			count++;
			scanf("%d%d",&len,&cost);
			int i;total_time[0]=0;
			for(i=1;i<=n;i++)
			{
				scanf("%d",&time[i]);
				total_time[i]=total_time[i-1]+time[i];
			}
			printf("Case %d:\n\n",count);
			end_n=0;int pre=0;
			max_state[0]=0;
			for(i=1;i<=n;i++)
			{
				if(total_time[i]-total_time[pre]>len)
				{					
					end_n++;
					max_state[end_n]=i-1;
					pre=i-1;
				}
			}
			end_n++;max_state[end_n]=n;
/*
			for(i=0;i<=n;i++)
				printf("%d  ====>  %d\n",i,total_time[i]);
			printf("\n");

			for(i=0;i<=end_n;i++)
				printf("%d  ====  %d\n",i,max_state[i]);
			printf("\n");
*/
			printf("Minimum number of lectures: %d\n",end_n);
			memset(flag,0,sizeof(flag));
			flag[0][0]=true;
			val[0][0]=0;
			search(end_n,n);

/*

  //	down-top method  need too many not necessary calculate

			int j;
			int val[2][1001];
			bool flag[2][1001];
			for(i=0;i<=n;i++)
				flag[0][i]=false;
			flag[0][0]=true;int pt;
			val[0][0]=0;
			for(i=1;i<=end_n;i++)
			{
				pt=i%2;
				for(j=0;j<=max_state[i];j++)	flag[pt][j]=false;
				for(j=0;j<=max_state[i];j++)
				{
					int k;					
					for(k=0;k<=min(j,max_state[i-1]);k++)
					{
						//if(flag[1-pt][k]==false)	break;
						int left=total_time[j]-total_time[k];
						if(left>len)	continue;
						int tempval=cal(left,len);						
						if(!flag[pt][j]||val[pt][j]>tempval+val[1-pt][k])
						{
							val[pt][j]=tempval+val[1-pt][k];
							flag[pt][j]=true;
						}
					}
					
	//				printf("%d--%d---->%d\n",i,j,val[pt][j]);
			
				}
			}
*/
			
			printf("Total dissatisfaction index: %d\n",val[end_n][n]);
		}
	}
	return 0;
}
					





		