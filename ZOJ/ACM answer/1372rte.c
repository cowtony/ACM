#include <stdio.h>
int main()
{
	unsigned int point,route;
	unsigned temp[51],ted,m,n;
	unsigned int ppl[50000][3];
	unsigned int i,j;
	while(1)
	{
		scanf("%d",&point);
		if(point==0) break;
		scanf("%d",&route);
		if(point==1) {printf("0\n\n");continue;}
		for(i=1;i<=point;i++)
		{
			temp[i]=0;
		}
		for(i=0;i<route;i++)
		{
			scanf("%d%d%d",&ppl[i][0],&ppl[i][1],&ppl[i][2]);
		}
		for(i=0;i<route-1;i++)
		{
			for(j=i;j<route;j++)
			{
				if(ppl[j][2]<ppl[i][2])
				{
					ted=ppl[j][0];
					ppl[j][0]=ppl[i][0];
					ppl[i][0]=ted;
                    ted=ppl[j][1];
					ppl[j][1]=ppl[i][1];
					ppl[i][1]=ted;
					ted=ppl[j][2];
					ppl[j][2]=ppl[i][2];
					ppl[i][2]=ted;
				}
			}
		}
		n=0;m=0;
		for(i=0;;i++)
		{
			if(temp[ppl[i][0]]==0||temp[ppl[i][1]]==0)
			{
				temp[ppl[i][0]]=1;
				temp[ppl[i][1]]=1;
				n+=ppl[i][2];m++;
				if(m==point-1) break;
			}
			else continue;
		}
		printf("%d\n\n",n);
	}
	return 0;
}






