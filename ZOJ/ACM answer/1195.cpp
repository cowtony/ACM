#include <cstdio>
//本题主要是边界问题没想：以后要注意啊！！！！！
struct devices 
{
	int state;
	int power ;
};


int main()
{
	devices ele[21];
	int i,j,nd,seq,cf, test=1;
	
	while(scanf("%d%d%d",&nd,&seq,&cf)==3&&(nd||seq||cf))
	{	int temp_power=0,oper=0,blown=0,max_power=0;
		for(i=1;i<=nd;i++)
		{
			scanf("%d",&ele[i].power);
			ele[i].state=0;
		}
		for(j=1;j<=seq;j++)
		{
			scanf("%d",&oper);
			if(ele[oper].state)
			{temp_power-=ele[oper].power;
			ele[oper].state=0;}
			else
			{
				temp_power+=ele[oper].power;
				max_power=max_power>temp_power?max_power:temp_power;
				if(max_power>cf)  blown=1;
					
				ele[oper].state=1;
				
			}
		}
	
	
	
		if(blown)
			printf("Sequence %d\nFuse was blown.\n\n",test++);
		else
			printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",test++,max_power);	
		
	}
	return 0;
}