#include <stdio.h>
#include <string.h>
int main()
{
	char str[100][30];
	int a[100][8];
	int team;
	int b[100][2];
	int i,j,k,t;
	int pro,pena,time;
	scanf("%d%*c",&team);
	i=0;
	while(team--)
	{
		scanf("%s",&str[i]);
		t=0;
		for(j=0;j<8;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0) t++;
		}
		scanf("%*c");
		b[i][0]=4-t;
		time=0;
		for(j=0;j<7;j+=2)
		{
			if(!a[i][j+1]) continue;
			time+=(a[i][j+1]+20*(a[i][j]-1));
		}
		b[i][1]=time;
		i++;
	}
	pro=b[0][0];
	pena=b[0][1];
	k=0;
	for(j=1;j<i;j++)
	{
		if(b[j][0]>pro)
		{
			pro=b[j][0];
			pena=b[j][1];
			k=j;
		}
		else if(b[j][0]==pro)
		{
			if(b[j][1]<pena)
			{
				pro=b[j][0];
				pena=b[j][1];
				k=j;
			}
		}
	}
	printf("%s %d %d\n",str[k],pro,pena);
	return 0;
}




