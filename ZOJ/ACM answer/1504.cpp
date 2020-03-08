//90197 2003-03-16 22:27:07 Wrong Answer 1504 C++ 00:00.01 432K Century Ghost 
//90004 2003-03-16 17:30:17 Wrong Answer 1504 C++ 00:00.00 432K Century Ghost 

#include<stdio.h>

struct nodetype
{
	int x,y;
	char ch;
};
nodetype node[100];
int dis(int i,int j)
{
	return ((node[i].x-node[j].x)*(node[i].x-node[j].x)+3*(node[i].y-node[j].y)*(node[i].y-node[j].y));
}
int can_form(int i,int j,int k)
{
	if(dis(i,j)==dis(i,k)&&dis(i,j)==dis(j,k))	return 1;
	return 0;
}
int main()
{
	int n;
	while(scanf("%d",&n))
	{
		if(n==0)	break;
		int total=(n*(n+1))/2;	
		int i;
		int temppt=1;int pt=2;
		int tempx=12,tempy=12,movex=12;
		char string[100];char flush;
		scanf("%c",&flush);
		for(i=1;i<=total;i++)
		{	
			scanf("%c",&node[i].ch);
			node[i].x=movex;node[i].y=tempy;
			movex+=2;
			if(i==temppt)
			{
				temppt+=pt;pt++;
				tempx--;movex=tempx;
				tempy--;
			}
		}
		int flag[27];int j,t;
		for(i=0;i<27;i++)	flag[i]=-1;
		for(i=1;i<=total;i++)
		{
			if(flag[i]>=0)	continue;
			char temp=node[i].ch;
			for(j=i+1;j<=total;j++)		
				if(node[j].ch==temp)				
				{
					for(t=j+1;t<=total;t++)					
						if(node[t].ch==temp)
						{
							if(can_form(i,j,t))	flag[temp-'a']=1;
							break;
						}
					break;
				}
			if(flag[temp-'a']==-1) flag[temp-'a']=0;
		}
		int find=0;
		for(i=0;i<27;i++)
			if(flag[i]==1)	{find=1;printf("%c",(i+'a'));}
		if(!find)	printf("LOOOOOOOOSER!");
		printf("\n");
	}
	return 0;
}








			
			
			

		
