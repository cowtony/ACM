#include <iostream>

using namespace std;
int main()
{
	int n,m;
	int temp1,temp2;
	int i,j;
	int val,num;
	int p=0;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(p) printf("\n");
		else p=1;
        int nu1[1001];//被乘数
		int now[1001];//结果
		memset(nu1,0,sizeof(nu1));
		memset(now,0,sizeof(now));
		scanf("%d%d",&val,&num);
		temp1=0;
		for(i=0;(i==0||n/(i*val)>=1)&&i<=num;i++)
		{
			nu1[i*val]=1;
			now[i*val]=1;
		}
		temp1=i*val>temp1? i*val+1:temp1;
		m--;
		while(m--)
		{
			temp2=temp1-1;;
			scanf("%d%d",&val,&num);
			for(i=1;i<=num&&n/(i*val)>=1;i++)//从新的去找新项 
			{
				for(j=0;j<temp1;j++)
				{
                    			if(nu1[j]==0) continue;
					if(j+i*val>n) break;
					now[j+i*val]+=nu1[j];
					if(j+i*val>temp2) temp2=j+i*val;			
				}
			}
			for(i=0;i<=temp2;i++)
			{
				nu1[i]=now[i];
			}
			temp1=temp2+1;
		}
		printf("%d\n",now[n]);
	}
	return 0;
}
