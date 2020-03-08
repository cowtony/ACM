//258109 2003-08-15 12:29:39 Presentation Error 1128 C++ 00:00.01 1020K just for play 
//258111 2003-08-15 12:30:49 Accepted 1128 C++ 00:00.01 1016K just for play 
//258114 2003-08-15 12:37:03 Accepted 1128 C++ 00:00.01 392K just for play 
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;


const double PE=1.0e-8;
struct POINT{double x,y;};
struct DIS{double from,to;};

POINT alant_map[201];
int seq[201];
DIS array[201];
int array_used;
int cur;

int cmp(const void* fir,const void* sec)
{
	if(alant_map[*(int*)fir].x>alant_map[*(int*)sec].x+PE||
		(fabs(alant_map[*(int*)fir].x-alant_map[*(int*)sec].x)<PE&&(*(int*)fir)%2==1))
		return true;
	return false;
}
int y_cmp(const void* fir,const void* sec)
{
	if(array[*(int*)fir].from>array[*(int*)sec].from+PE)		
		return true;
	return false;
}
int main()
{
//	freopen("1128.in","r",stdin);
//	freopen("1128.out","w",stdout);
	int n;int count=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		int i,j;
		count++;
		for(i=0;i<n;i++)		
			scanf("%lf %lf %lf %lf",&alant_map[2*i].x,&alant_map[2*i].y,&alant_map[2*i+1].x,&alant_map[2*i+1].y);
		for(i=0;i<2*n;i++)	seq[i]=i;
		qsort(seq,2*n,sizeof(int),cmp);
/*
		for(i=0;i<2*n;i++)
			printf("%lf %lf\n",alant_map[seq[i]].x,alant_map[seq[i]].y);
*/
		
		int in_stack[201];
		int stack_used=0;
		double area=0;
		for(i=0;i<2*n;i++)
		{	
/*			
			printf("%d    %d -> \n",i,stack_used);
			for(j=0;j<stack_used;j++)
				printf("%d ",in_stack[j]);
			printf("\n");
*/
			array_used=stack_used;
			for(j=0;j<stack_used;j++)
			{
				array[j].from=alant_map[in_stack[j]].y;
				array[j].to=alant_map[in_stack[j]+1].y;
			}
			if(seq[i]%2==0)			
				in_stack[stack_used++]=seq[i];
			else
			{				
				for(j=0;j<stack_used;j++)
					if(in_stack[j]/2==seq[i]/2)	break;
				in_stack[j]=in_stack[stack_used-1];
				stack_used--;				
			}
		
			if(array_used==0)	continue;
			int yseq[201];
			cur=i;
			for(j=0;j<array_used;j++)
				yseq[j]=j;
			qsort(yseq,array_used,sizeof(int),y_cmp);
/*
			printf("%d -------\n",i);
			for(j=0;j<array_used;j++)
				printf("%lf %lf\n",array[yseq[j]].from,array[yseq[j]].to);
*/
			double max_y=array[yseq[0]].to;
			double min_y=array[yseq[0]].from;
			for(j=1;j<array_used;j++)
			{
				if(array[yseq[j]].from+PE<max_y)
				{
					if(array[yseq[j]].to>max_y+PE)	max_y=array[yseq[j]].to;
				}
				else
				{
					area+=(alant_map[seq[i]].x-alant_map[seq[i-1]].x)*(max_y-min_y);
					min_y=array[yseq[j]].from;max_y=array[yseq[j]].to;
				}
			}
			area+=(alant_map[seq[i]].x-alant_map[seq[i-1]].x)*(max_y-min_y);
		}
		printf("Test case #%d\n",count);
		printf("Total explored area: %.2lf\n\n",area);
		
	}
	return 0;
}